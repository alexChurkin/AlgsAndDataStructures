
int find_insert_position_linearly(int arr[], int right, int* comp_count)
{
	int j, pos = right;
	for (j = 0; j < right; j++)
	{
		(*comp_count)++;
		if (arr[right] <= arr[j])
		{
			pos = j;
			break;
		}
	}
	return pos;
}

int find_insert_position_binary(int arr[], int right, int* comp_count)
{
	int l = 0, r = right - 1, c;
	while (l <= r)
	{
		c = (l + r) / 2;
		(*comp_count)++;
		if (arr[right] < arr[c])
			r = c - 1;
		else
			l = c + 1;
	}
	return r + 1;
}

int get_min_index(int arr[], int size)
{
	int index = 0, i;
	for (int i = 0; i < size; i++)
		if (arr[i] < arr[index])
			index = i;
	return index;
}

int get_max_index(int arr[], int size)
{
	int index = 0, i;
	for (int i = 0; i < size; i++)
		if (arr[i] > arr[index])
			index = i;
	return index;
}

void merge_sorted_parts(
	int arr[], int l, int c, int r,
	int* comp_count, int* swap_count)
{
	int i = l,
		j = c + 1,
		t = 0;
	int* temp_arr;
	temp_arr = (int*)malloc((r - l + 1) * sizeof(int));

	while (i <= c && j <= r)
	{
		(*comp_count)++;
		if (arr[i] <= arr[j])
		{
			temp_arr[t] = arr[i], i++;
		}
		else
		{
			temp_arr[t] = arr[j], j++;
		}
		t++;
	}

	while (i <= c)
	{
		temp_arr[t] = arr[i];
		t++;
		i++;
	}
	while (j <= r)
	{
		temp_arr[t] = arr[j];
		t++;
		j++;
	}

	for (int i = l; i <= r; i++)
	{
		(*swap_count)++;
		arr[i] = temp_arr[i - l];
	}
	free(temp_arr);
}