/* 
 * File:   main.cpp
 * Author: NornubariKanabolo
 * Gaddis 7th Edition Chapter 4 Problem 18
 * Wavelengths
 * Created on July 7, 2014, 3:26 PM
 */

#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //Declare variables
    const float mw_upb = 1e-2;
    const float infr_upb = 1e-3;
    const float vis_upb = 7e-7;
    const float uv_upb = 4e-7;
    const float xray_upb = 1e-8;
    const float gam_upb = 1e-11;
    //Input Wavelength
    float wavelength;
    cout<<"Please enter a wavelength(in meters): ";
    cin>>wavelength;
    cout<<endl;
    //Outputs
    string rad_type;//Radiation type
    rad_type=(wavelength<=gam_upb)?"Gamma Rays":
             (wavelength<=xray_upb)?"X Rays":
             (wavelength<=uv_upb)?"Ultraviolet":
             (wavelength<=vis_upb)?"Visible Light":
             (wavelength<=infr_upb)?"Infrared":
             (wavelength<=mw_upb)?"Microwaves":"Radio Waves";
    cout<<"The type of radiation is for wavelength "<<wavelength<<"meters is: "<<rad_type<<endl;
    return 0;
}

