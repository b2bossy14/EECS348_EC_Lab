#include <stdio.h>


int main() {

    // Initialize an array to hold the months using a pointer
    char *months[12] = {"January", "February", "March", "April", 
                        "May", "June", "July", "August", "September", 
                        "October", "November", "December"};
    
    // Empty array to hold the sales
    float monthly_sales[12];
    printf("\n");

    // Gather inputs on sales data
    printf("Enter the sales of for the year:\n");
    for (int i = 0; i < 12; i++) {
        
        scanf("%f", &monthly_sales[i]);
    }

    printf("\nMonthly Sales Report for 2024\n");

    printf("\nMonth        Sales\n");

    // Format the months and corresponding sales into readable and organized columns
    for (int i = 0; i < 12; i++) {
        printf("%-12s  %.2f\n", months[i], monthly_sales[i]);
    }

    printf("\nSales summary report:\n");

    // Check for the lowest sales month
    float min = monthly_sales[0];
    int minIndex = 0;

        for (int i = 1; i < 12; i++)
        {
            if (monthly_sales[i] < min) {
                min = monthly_sales[i];
                minIndex = i;
            }
        }
    //Check for the highest sales month
    float max = monthly_sales[0];
    int maxIndex = 0;

        for (int i = 1; i < 12; i++)
        {
            if (monthly_sales[i] > max) {
                max = monthly_sales[i];
                maxIndex = i;
            }
        } 

    // Find the average of the years monthly sales
    float total_sales = 0;
    for (int i = 0; i < 12; i++){
        total_sales = total_sales + monthly_sales[i];
    }

    float average_monthly_sales = total_sales / 12;
    
    
    printf("\nMinimum Sales: %.2f (%s)", min, months[minIndex]);
    printf("\nMaximum Sales: %.2f (%s)", max, months[maxIndex]);
    printf("\nAverage sales: %.2f\n\n", average_monthly_sales);

    printf("\nSix-month average report:\n\n");

    float one_six = 0;

    for (int i = 0; i < 6; i++){
        one_six = one_six + monthly_sales[i];
    }

    float one_six_average = one_six / 6;


    float two_seven = 0;

    for (int i = 1; i < 7; i++){
        two_seven = two_seven + monthly_sales[i];
    }

    float two_seven_average = two_seven / 6;

    
    float three_eight = 0;

    for (int i = 2; i < 8; i++){
        three_eight = three_eight + monthly_sales[i];
    }

    float three_eight_average = three_eight / 6;



    float four_nine = 0;

    for (int i = 3; i < 9; i++){
        four_nine = four_nine + monthly_sales[i];
    }

    float four_nine_average = four_nine / 6;



    float five_ten = 0;

    for (int i = 4; i < 10; i++){
        five_ten = five_ten + monthly_sales[i];
    }

    float five_ten_average = five_ten / 6;


    float six_eleven = 0;

    for (int i = 5; i < 11; i++){
        six_eleven = six_eleven + monthly_sales[i];
    }

    float six_eleven_average = six_eleven / 6;



    float seven_twelve = 0;

    for (int i = 6; i < 12; i++){
        seven_twelve = seven_twelve + monthly_sales[i];
    }

    float seven_twelve_average = seven_twelve / 6;

    /*
    Created multiple loops that check the sales of each possible 6-month combination.
    Divide the total of those 6 months by 6 to find each 6-month average.
    Probably a simpler way to write this but it works.
    */

    printf("January-June: %.2f\n", one_six_average);
    printf("February-July: %.2f\n", two_seven_average);
    printf("March-August: %.2f\n", three_eight_average);
    printf("April-September: %.2f\n", four_nine_average);
    printf("May-October: %.2f\n", five_ten_average);
    printf("June-November: %.2f\n", six_eleven_average);
    printf("July-December: %.2f\n", seven_twelve_average);



    int n = sizeof(monthly_sales) / sizeof(monthly_sales[0]);

    for (int i = 0; i < n - 1; i++) {

        int maxIndexx = i;

        for (int j = i+1; j < n; j++) {

            if (monthly_sales[j] > monthly_sales[maxIndexx]) {
                maxIndexx = j;  
            }
        }

        if (maxIndexx != i) {

            float temp = monthly_sales[maxIndexx];

            monthly_sales[maxIndexx] = monthly_sales[i];
            monthly_sales[i] = temp;
        }

        char *temp_month = months[maxIndexx];
        months[maxIndexx] = months[i];
        months[i] = temp_month;
    }

    printf("\nSales report (highest to lowest):\n");

    printf("\nMonth        Sales\n");

    for (int i = 0; i < 12; i++) {
        printf("%-12s  $%.2f\n", months[i], monthly_sales[i]);
    }

    /*
     - n is total number of elements in the 'monthly_sales'
     - First for-loop iterates through each element in the 'monthly_sales'
     - maxIndexx is initialized as the index of the current element 'i'
     - Inner for-loop checks for maximum sales after element 'i'.
     - Once a higher index is found, update maxIndexx is updated
     - If highest value is not at index i, swap highest value and index i
     - Use pointer to also swap the months of corresponding maxIndexx and index i swaps
    
    */
    

}


