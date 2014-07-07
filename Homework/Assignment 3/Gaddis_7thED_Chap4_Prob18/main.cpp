/* 
 * File:   main.cpp
 * Author: Nornubari's Laptop
 *
 * Created on July 7, 2014, 3:26 PM
 */

#include <cstdlib>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //Declare variables
    const float GAM_UB = 1e-11;//Upper bound on Gamma Rays
    const float X_UB = 1e-8;//Upper bound on X Rays
    const float UV_UB = 4e-7;//Upper bound on Ultraviolet radiation
    const float VL_UB = 7e-7;//Upper bound on Visible Light
    const float IR_UB = 1e-3;//Upper bound on Infrared radiation
    const float MW_UB = 1e-2;//Upper bound on Microwaves
    //Inputs
    float wav_len;//Wavelength given by user
    //Outputs
    string rad_type;//Radiation type
    //Get wavelength from user
    cout<<"Please enter a wavelength(in meters): ";
    cin>>wav_len;
    cout<<endl;
    //Determine what type of radiation the given wavelength is
    rad_type=(wav_len<=GAM_UB)?"Gamma Rays":
             (wav_len<=X_UB)?"X Rays":
             (wav_len<=UV_UB)?"Ultraviolet":
             (wav_len<=VL_UB)?"Visible Light":
             (wav_len<=IR_UB)?"Infrared":
             (wav_len<=MW_UB)?"Microwaves":"Radio Waves";
    //Output the radiation type to the screen
    cout<<"The type of radiation is: "<<rad_type<<endl;
    return 0;
}

