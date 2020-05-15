//
// Created by eyal on 19/12/18.
//

#ifndef FLIGHTPROJECTA_SYMTBLCLASS_H
#define FLIGHTPROJECTA_SYMTBLCLASS_H

#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <regex>
#include "Command.h"
#include "TCPClient.h"
#include <atomic>
#include <bits/stdc++.h>
#include <vector>

class symTblClass {
    static map<string,double> symTbl; // string - the symbol name, double - the value of this parameter
    static map<string,string> bindedSymTbl; //left is the symbol right is the adress i.e lo/ca/tio/n
public:
    static TCPClient client;

    // the sampled values
    static atomic<double> airspeed_indicator_indicated_speed_kt;
    static atomic<double> altimeter_indicated_altitude_ft;
    static atomic<double> altimeter_pressure_alt_ft;
    static atomic<double> attitude_indicator_indicated_pitch_deg;
    static atomic<double> attitude_indicator_indicated_roll_deg;
    static atomic<double> attitude_indicator_internal_pitch_deg;
    static atomic<double> attitude_indicator_internal_roll_deg;
    static atomic<double> encoder_indicated_altitude_ft;
    static atomic<double> encoder_pressure_alt_ft;
    static atomic<double> gps_indicated_altitude_ft;
    static atomic<double> gps_indicated_ground_speed_kt;
    static atomic<double> gps_indicated_vertical_speed;
    static atomic<double> indicated_heading_deg;
    static atomic<double> magnetic_compass_indicated_heading_deg;
    static atomic<double> slip_skid_ball_indicated_slip_skid;
    static atomic<double> turn_indicator_indicated_turn_rate;
    static atomic<double> vertical_speed_indicator_indicated_speed_fpm;
    static atomic<double> flight_aileron;
    static atomic<double> flight_elevator;
    static atomic<double> flight_rudder;
    static atomic<double> flight_flaps;
    static atomic<double> engine_throttle;
    static atomic<double> engine_rpm;

    static double GetValueOfBinded(string);
    static bool addSym(const string);
    static bool addBinded(const string, const string);
    static double getVlaue(const string);
    static bool isBinded(const string);
    static bool isSym(const string);
    static bool setSym(const string, const double);
    static string getBind(string);
};


#endif //FLIGHTPROJECTA_SYMTBLCLASS_H
