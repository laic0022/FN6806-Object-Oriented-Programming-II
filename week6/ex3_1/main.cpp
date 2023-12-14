#include<iostream>
#include<cmath>
#include<vector>
#include<random>
#include <valarray>

using namespace std;

using path = vector<double>;
using multipath = vector<path>;

auto vasicek(double sigma, double kappa, double r_mean, double r0, double T, int paths, int steps, mt19937 &gen) {
    double dt = T / steps;
    vector<double> sum_rates(paths);
    vector<double> end_rates(paths);
    

    vector<double> v(steps + 1, r0);
    static normal_distribution<double> nd(0.0, 1.0);


    multipath traj;

    for (int n = 0; n < paths; n++) {
        for (int i = 1; i <= steps; ++i) {
            v[i] = v[i - 1] + kappa * (r_mean - v[i - 1]) * dt + sigma * sqrt(dt) *nd(gen);
        }
        traj.emplace_back(v);
        end_rates[n] = traj[n].back();
        sum_rates[n] = accumulate(next(traj[n].begin(), 1), traj[n].end(), 0.0);
    }
    return make_tuple(end_rates, sum_rates);
}
auto vasicek_valarray(double sigma, double kappa, double r_mean, double r0, double T, int paths, int steps, mt19937 &gen) {
    double dt = T / steps;
    valarray<double> sum_rates(0.0, paths);
    valarray<double> end_rates(r0, paths);
    

    vector<double> v(steps + 1, r0);
    static normal_distribution<double> nd(0.0, 1.0);


    multipath traj;

    for (int n = 0; n < paths; n++) {
        for (int i = 1; i <= steps; ++i) {
            v[i] = v[i - 1] + kappa * (r_mean - v[i - 1]) * dt + sigma * sqrt(dt) *nd(gen);
        }
        traj.emplace_back(v);
        end_rates[n] = traj[n].back();
        sum_rates[n] = accumulate(next(traj[n].begin(), 1), traj[n].end(), 0.0);
    }
    return make_tuple(end_rates, sum_rates);
}
int main(){
    // market data
    const double r0{0.05};
    // vasicek
    const double kappa = 0.82;
    const double sigma = 0.1;
    const double r_mean = 0.05;
    // mc simulation
    // const int paths = 20'000;
    // const double dt{1/365.0};
    // time to maturity
    const double T{0.5};
    // const int steps{static_cast<int>(T/dt)};

    seed_seq seed{90127};
    auto mtgen = mt19937{seed};
    auto [end_rates, sum_rates] = vasicek(sigma, kappa, r_mean, r0, T, 20'000, int(0.5 * 365), mtgen);
    auto end_rates_avg = accumulate(end_rates.begin(), end_rates.end(), 0.0) / end_rates.size();
    auto sum_rates_avg = accumulate(sum_rates.begin(), sum_rates.end(), 0.0) / sum_rates.size();
    cout << end_rates_avg << ", " << sum_rates_avg << endl;
    // 0.0495695, 9.05915


    mtgen.seed(seed);
    auto [end_rates2, sum_rates2] = vasicek_valarray(sigma, kappa, r_mean, r0, T, 20'000, int(0.5 * 365), mtgen);
    end_rates_avg = accumulate(begin(end_rates2), end(end_rates2), 0.0) / end_rates2.size();
    sum_rates_avg = accumulate(begin(sum_rates2), end(sum_rates2), 0.0) / sum_rates2.size();
    cout << end_rates_avg << ", " << sum_rates_avg << endl;
    // 0.0495608, 9.06302

    return 0;
}