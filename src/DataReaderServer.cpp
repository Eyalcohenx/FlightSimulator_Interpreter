#include "DataReaderServer.h"
#include "symTblClass.h"
#include "OpenServerCommand.h"

bool DataReaderServer::stillWorking = true;

void* DataReaderServer::createServer(void* arg) {
    //extracting out server details
    struct ServerDetails* det = (struct ServerDetails*) arg;
    int portno = det->portno;
    int hz = det->hz;
    double timeToSleep = 1/(double)hz;

    int sockfd, newsockfd, clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int  n;
    double num;

    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    /* Now start listening for the clients, here process will
       * go in sleep mode and will wait for the incoming connection
    */

    listen(sockfd,5);
    clilen = sizeof(cli_addr);

    /* Accept actual connection from the client */
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen);

    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    /* If connection is established then start communicating */
    bzero(buffer,256);

    while(stillWorking) {
        n = read(newsockfd, buffer, 255);

        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        //replacing ',' with ' ' to use it with the stream
        for(int i = 0; i < 256; i++){
            if(buffer[i] == ',')
                buffer[i] = ' ';
        }

        istringstream iss(buffer);

        // starting to load variables
        iss >> num;
        symTblClass::airspeed_indicator_indicated_speed_kt.exchange(num,memory_order_seq_cst);
        iss >> num;
        symTblClass::altimeter_indicated_altitude_ft.exchange(num,memory_order_seq_cst);
        iss >> num;
        symTblClass::altimeter_pressure_alt_ft.exchange(num,memory_order_seq_cst);
        iss >> num;
        symTblClass::attitude_indicator_indicated_pitch_deg.exchange(num,memory_order_seq_cst);
        iss >> num;
        symTblClass::attitude_indicator_indicated_roll_deg.exchange(num,memory_order_seq_cst);
        iss >> num;
        symTblClass::attitude_indicator_internal_pitch_deg.exchange(num,memory_order_seq_cst);
        iss >> num;
        symTblClass::attitude_indicator_internal_roll_deg.exchange(num,memory_order_seq_cst);
        iss >> num;
        symTblClass::encoder_indicated_altitude_ft.exchange(num,memory_order_seq_cst);
        iss >> num;
        symTblClass::encoder_pressure_alt_ft.exchange(num,memory_order_seq_cst);
        iss >> num;
        symTblClass::gps_indicated_altitude_ft.exchange(num,memory_order_seq_cst);
        iss >> num;
        symTblClass::gps_indicated_ground_speed_kt.exchange(num,memory_order_seq_cst);
        iss >> num;
        symTblClass::gps_indicated_vertical_speed.exchange(num,memory_order_seq_cst);
        iss >> num;
        symTblClass::indicated_heading_deg.exchange(num,memory_order_seq_cst);
        iss >> num;
        symTblClass::magnetic_compass_indicated_heading_deg.exchange(num,memory_order_seq_cst);
        iss >> num;
        symTblClass::slip_skid_ball_indicated_slip_skid.exchange(num,memory_order_seq_cst);
        iss >> num;
        symTblClass::turn_indicator_indicated_turn_rate.exchange(num,memory_order_seq_cst);
        iss >> num;
        symTblClass::vertical_speed_indicator_indicated_speed_fpm.exchange(num,memory_order_seq_cst);
        iss >> num;
        symTblClass::flight_aileron.exchange(num,memory_order_seq_cst);
        iss >> num;
        symTblClass::flight_elevator.exchange(num,memory_order_seq_cst);
        iss >> num;
        symTblClass::flight_rudder.exchange(num,memory_order_seq_cst);
        iss >> num;
        symTblClass::flight_flaps.exchange(num,memory_order_seq_cst);
        iss >> num;
        symTblClass::engine_throttle.exchange(num,memory_order_seq_cst);
        iss >> num;
        symTblClass::engine_rpm.exchange(num,memory_order_seq_cst);


        // indication connection was made and we got the first initializing values
        OpenServerCommand::connection_indicator.exchange(1,memory_order_seq_cst);

        //zero out the buffer
        bzero(buffer,256);

    }

    return 0;
}

void DataReaderServer::CreateServerThread(int portno, int hz) {
    //using stuct to send to the pthread the details of the server
    struct ServerDetails* deta = new ServerDetails();
    deta->portno = portno;
    deta->hz = hz;
    pthread_t trid;
    //creating the thread and starting to run it
    pthread_create(&trid, nullptr, createServer, deta);

}
