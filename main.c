#include <stdio.h>

int main() {
    int numHouseholds, i;
    float consumption;
    float bill;
    
    // Accumulators and counters for summary
    float totalConsumption = 0;
    float totalBilling = 0;
    int highConsumers = 0;

    printf("=== ELECTRIC COOPERATIVE BILLING SYSTEM ===\n");
    printf("Enter the number of households to process: ");
    if (scanf("%d", &numHouseholds) != 1 || numHouseholds <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    for (i = 1; i <= numHouseholds; i++) {
        printf("\n--- Household %d ---\n", i);
        printf("Enter electricity consumption (kWh): ");
        scanf("%f", &consumption);

        // Input validation for negative values
        if (consumption < 0) {
            printf("Consumption cannot be negative. Please re-enter this household.\n");
            i--; // Repeat iteration
            continue;
        }

        // Calculate bill based on tiered rates
        if (consumption <= 100) {
            bill = consumption * 10.0;
        } else {
            // First 100 kWh at 10 pesos, excess at 12 pesos
            bill = (100 * 10.0) + ((consumption - 100) * 12.0);
        }

        // Update summary metrics
        totalConsumption += consumption;
        totalBilling += bill;

        if (consumption > 100) {
            highConsumers++;
        }

        // Display individual bill
        printf("Bill for Household %d: PHP %.2f\n", i, bill);
    }

    // Display final summary report
    printf("\n========================================\n");
    printf("            SUMMARY REPORT              \n");
    printf("========================================\n");
    printf("Total Electricity Consumption : %.2f kWh\n", totalConsumption);
    printf("Total Billing Amount          : PHP %.2f\n", totalBilling);
    printf("Households > 100 kWh          : %d\n", highConsumers);
    printf("========================================\n");

    return 0;
}