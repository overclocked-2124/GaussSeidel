#include<iostream>
#include<iomanip>
#include<cmath>

int main() {
    float a[10], b[4], x1 = 0, y1 = 0, z1 = 0, x2, y2, z2;
    bool flag = true;
    int j = 1;

    // Initialize array elements to zero
    for (int i = 0; i < 10; i++) a[i] = 0;
    for (int i = 0; i < 4; i++) b[i] = 0;

    std::cout << "Enter the matrix elements after making it diagonally dominant (a[1] to a[9]): ";
    for (int i = 1; i <= 9; i++) std::cin >> a[i];

    std::cout << "Enter the elements of the b matrix (b[1] to b[3]): ";
    for (int i = 1; i <= 3; i++) std::cin >> b[i];

    while (flag) {
        x2 = (b[1] - a[2] * y1 - a[3] * z1) / a[1];
        y2 = (b[2] - a[4] * x2 - a[6] * z1) / a[5];
        z2 = (b[3] - a[7] * x2 - a[8] * y2) / a[9];

        std::cout << "Iteration " << j << std::endl;
        std::cout << "x1: " << x2 << ", y1: " << y2 << ", z1: " << z2 << std::endl;

        // Check for convergence
        if (std::fabs(x2 - x1) < 0.0001 && std::fabs(y2 - y1) < 0.0001 && std::fabs(z2 - z1) < 0.0001) {
            flag = false;
        }

        // Update values for next iteration
        x1 = x2;
        y1 = y2;
        z1 = z2;
        j++;
    }

    return 0;
}
