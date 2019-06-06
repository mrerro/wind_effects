#include "Wind.hpp"

Wind::Wind(double M, double S, 
           double x0, double y0, double z0,
           double V0, double alpha, double beta,
           double p, double wx, double wy) : RungeKutta (6)
{
    this->M = M;
    this->S = S;

    this->wx = wx;
    this->wy = wy;

    this->p = p;

    std::vector<double> Y0(6);    
    Y0[0] = x0;
    Y0[1] = y0;
    Y0[2] = z0;
    Y0[3] = fabs(V0)*cos(alpha*(M_PI/180))*sin(beta*(M_PI/180));
    Y0[4] = fabs(V0)*cos(alpha*(M_PI/180))*cos(beta*(M_PI/180));
    Y0[5] = fabs(V0)*sin(alpha*(M_PI/180));
    SetInit(0, Y0);
}

std::vector<double> Wind::F(double time, std::vector<double> &coordinates) {
    // x'=Vx - FY[0] = Y[3]
    // y'=Vy - FY[1] = Y[4] 
    // z'=Vz - FY[2] = Y[5]
    // Vx'=... FY[3] =  
    // Vy'=... FY[4] =  
    // Vy'=... FY[5] =  

    Vx = Y[3];
    Vy = Y[4];
    Vz = Y[5];

    FY[0] = Y[3];
    FY[1] = Y[4];
    FY[2] = Y[5];
    FY[3] = (- 0.5*C*p*S*(Vx-wx)*std::abs(Vx-wx))/M;
    FY[4] = (- 0.5*C*p*S*(Vy-wy)*std::abs(Vy-wy))/M;
    FY[5] = (- M*g - 0.5*C*p*S*Vz*std::abs(Vz))/M;
    return FY;
}

double Wind::Step(int interval) {
    NextStep(((double)interval) / 1000.0);
    return t;
}

Wind::~Wind()
{
}
