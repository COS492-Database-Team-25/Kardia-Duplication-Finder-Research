/*
 * exp_fn_cos_compare
 * This method calculates the cosine similarity of two vector frequency tables
 * See centrallix-sysdoc/string_comparison.md for more information.
 *
 * Parameters:
 * 	tree : structure where output is stored
 *	objlist: 
 *	i0 : first data entry (pExpression)
 *	i1 : second data entry (pExpression)
 *	i2 :
 *
 * Returns:
 * 	0 	
 */
int exp_fn_cos_compare(pExpression tree, pParamObjects objlist, pExpression i0, pExpression i1, pExpression i2)
    {
    // Ensure function receives two non-null parameters
    if (!i0 || !i1)
	{
	mssError(1,"EXP","cos_compare() requires two parameter.");
	return -1;
	}

    // Ensure value passed in both parameters is not null
    if ((i0->Flags & EXPR_F_NULL) || (i1->Flags & EXPR_F_NULL))
	{
	tree->DataType = DATA_T_DOUBLE;
	tree->Flags |= EXPR_F_NULL;
	return 0;
	}

    // Ensure both parameters contain string values
    if ((i0->DataType != DATA_T_STRING) || (i1->DataType != DATA_T_STRING))
	{
	mssError(1,"EXP","cos_compare() requires two string parameters.");
	return -1;
	}

    //If the two strings are identical, don't bother running cosine compare	
    if (strcmp(i0->String, i1->String) == 0)
	{
	tree->DataType = DATA_T_DOUBLE;
	tree->Types.Double = 1.0;
	return 0;
	}

    // Allocate frequency tables (arrays of integers) for each term
    unsigned short *table1 = nmMalloc(EXP_VECTOR_TABLE_SIZE * sizeof(unsigned short));
    unsigned short *table2 = nmMalloc(EXP_VECTOR_TABLE_SIZE * sizeof(unsigned short));

    if (table1 == NULL || table2 == NULL)
	{
	mssError(1,"EXP","Memory allocation failed.");
	return -1;
	}

    // Calculate frequency tables for each term
    exp_fn_i_frequency_table(table1, i0->String);
    exp_fn_i_frequency_table(table2, i1->String);
	
    // Calculate dot product
    double dot_product = 0;
    exp_fn_i_dot_product(&dot_product, table1, table2);

    // Calculate magnitudes of each relative frequency vector
    double magnitude1 = 0;
    double magnitude2 = 0;
    exp_fn_i_magnitude(&magnitude1, table1);
    exp_fn_i_magnitude(&magnitude2, table2);
    
    tree->DataType = DATA_T_DOUBLE;
    tree->Types.Double = dot_product / (magnitude1 * magnitude2);
    nmFree(table1, EXP_VECTOR_TABLE_SIZE * sizeof(unsigned short));
    nmFree(table2, EXP_VECTOR_TABLE_SIZE * sizeof(unsigned short));

    return 0;
    }


/*
 * exp_fn_i_frequency_table
 * This method creates a vector frequency table based on a string of characters.
 *
 * Parameters:
 * 	table : integer pointer to vector frequency table (unsigned short)
 * 	term : the string of characters (char*)
 *
 * Returns:
 * 	0 	
 */
int exp_fn_i_frequency_table(unsigned short *table, char *term)
    {
    int i;
    // Initialize hash table with 0 values
    for (i = 0; i < EXP_VECTOR_TABLE_SIZE; i++)
	{
	table[i] = 0;
	}

	int j = -1;
    for(i = 0; i < strlen(term) + 1; i++)
	{
	// If latter character is punctuation or whitespace, skip it
	if (ispunct(term[i]) || isspace(term[i]))
	    {
	    continue;
	    }

	double temp1 = 0.0;
	double temp2 = 0.0;

	// If previous character is null
	if (j == -1)
	    {
	    temp1 = 96;
	    }

	// Else character is not null
	else
	    {
	    temp1 = (int)tolower(term[j]);
	    }

	// If latter character is null
	if (i == strlen(term))
	    {
	    temp2 = 96;
	    }

	// Else character is not null
	else
	    {
	    temp2 = (int)tolower(term[i]);
	    }

	// Else character is not null	// If either character is a number, reassign the code point
	if (temp1 >= 48 && temp1 <= 57)
	    {
	    temp1 += 75;
	    }

	if (temp2 >= 48 && temp2 <= 57)
	    {
	    temp2 += 75;
	    }



/*
 * exp_fn_i_dot_product
 * This method calculautes the dot product of two vectors.
 *
 * Parameters:
 * 	dot_product : the place where the result is stored (double)
 * 	r_freq_table1 : the first vector (unsigned short)
 * 	r_freq_table2 : the second vector (unsigned short)
 *
 * Returns:
 * 	0	
 */
int exp_fn_i_dot_product(double *dot_product, unsigned short *r_freq_table1, unsigned short *r_freq_table2)
    {
    int i;
    for (i = 0; i < EXP_VECTOR_TABLE_SIZE; i++) 
        {
	*dot_product = *dot_product + ((double)r_freq_table1[i] * (double)r_freq_table2[i]);
	}
    return 0;
    }

/*
 * exp_fn_i_magnitude
 * This method calculates the magnitude of a vector
 *
 * Parameters:
 * 	magnitude : the place where the result is stored (double)
 * 	r_freq_table : the vector (unsigned short)
 */
int exp_fn_i_magnitude(double *magnitude, unsigned short *r_freq_table)
    {
    int i;
    for (i = 0; i < EXP_VECTOR_TABLE_SIZE; i++)
	{
	*magnitude = *magnitude + ((double)r_freq_table[i] * (double)r_freq_table[i]);
	}
    *magnitude = sqrt(*magnitude);
    return 0;
    }




int cos_compare(pExpression tree, char* objlist, string i0, string i1, string i2)
{

}

int frequency_table(unsigned short *table, char *term)
{

}

int dot_product(double *dot_product, unsigned short *freq_table1, unsigned short *freq_table2)
{

}

int magnitude(double *magnitude, unsigned short freq_table)
{

}

int main(int argc, char* argv[]) 
{

}