#include <iostream>
#include <vector>
#include <memory>
#include <cmath>

class YieldCurve {
private:
    std::vector<double> m_rates;

public:
    YieldCurve(const std::vector<double>& rates) : m_rates(rates) {}

    // Interpolation function
    double interpolate(double time) const {
        // Implement your interpolation logic here (e.g., linear interpolation)
        // For simplicity, using linear interpolation for demonstration purposes
        if (time <= 0) {
            return m_rates[0];
        } else if (time >= m_rates.size() - 1) {
            return m_rates.back();
        } else {
            int floorIndex = static_cast<int>(std::floor(time));
            int ceilIndex = static_cast<int>(std::ceil(time));

            double floorRate = m_rates[floorIndex];
            double ceilRate = m_rates[ceilIndex];

            double t = time - floorIndex;

            return floorRate + t * (ceilRate - floorRate);
        }
    }
};

class FixedRateBond {
private:
    std::shared_ptr<YieldCurve> m_yieldCurve;
    double m_faceValue;  // Face value of the bond
    double m_couponRate; // Annual coupon rate
    double m_maturity;   // Time to maturity in years

public:
    FixedRateBond(std::shared_ptr<YieldCurve> yieldCurve, double faceValue, double couponRate, double maturity)
        : m_yieldCurve(yieldCurve), m_faceValue(faceValue), m_couponRate(couponRate), m_maturity(maturity) {}

    // Calculate the present value of the bond
    double presentValue() const {
        double presentValue = 0.0;

        for (int t = 1; t <= m_maturity; ++t) {
            double discountFactor = 1 / std::pow(1 + m_yieldCurve->interpolate(t), t);
            presentValue += m_couponRate * m_faceValue * discountFactor;
        }

        // Add face value discounted at maturity
        presentValue += m_faceValue / std::pow(1 + m_yieldCurve->interpolate(m_maturity), m_maturity);

        return presentValue;
    }
};

void test() {
    // Create YieldCurve instance with some arbitrary rates
    std::vector<double> yieldCurveData = {0.02, 0.025, 0.03, 0.035, 0.04};
    std::shared_ptr<YieldCurve> yieldCurve = std::make_shared<YieldCurve>(yieldCurveData);

    // Create Bond instances with arbitrary parameters
    FixedRateBond bond1(yieldCurve, 1000.0, 0.03, 5.0);
    FixedRateBond bond2(yieldCurve, 1500.0, 0.035, 7.0);

    // Get the present value of the bonds
    double price1 = bond1.presentValue();
    double price2 = bond2.presentValue();

    // Display the results
    std::cout << "Bond 1 Price: " << price1 << std::endl;
    std::cout << "Bond 2 Price: " << price2 << std::endl;
}

int main() {
    test();

    return 0;
}
