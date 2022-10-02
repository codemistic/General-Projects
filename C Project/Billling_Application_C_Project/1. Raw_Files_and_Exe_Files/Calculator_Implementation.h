#ifndef CALCULATOR_IMPLEMENTATION_H_INCLUDED
#define CALCULATOR_IMPLEMENTATION_H_INCLUDED

// Discount Calculator function is created to calculate final bill amount.

float Discount_Calculator(char customer_type[50], char product_number[50], int quantity, float product_cost)
{
	float discount, cost_total, final_amount;

	cost_total = product_cost * quantity;

	if (strcmp(customer_type, "S") == 0)
	{
		discount = 10;
		cost_total = cost_total - (cost_total *discount / 100);
	}

	final_amount = cost_total;

	if (final_amount > 1000)
	{
		discount = 5;
		final_amount = final_amount - (final_amount *discount / 100);

	}

	return final_amount;

}

#endif // CALCULATOR_IMPLEMENTATION_H_INCLUDED
