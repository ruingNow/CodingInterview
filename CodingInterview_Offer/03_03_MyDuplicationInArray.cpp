
//找出数组中所有重复的数字，及出现的次数
bool duplicate(int numbers[], int length)
{
    if(numbers == nullptr || length <= 0)
        return false;

    for(int i = 0; i < length; ++i)
    {
        if(numbers[i] < 0 || numbers[i] > length - 1)
            return false;
    }
	sort(numbers,numbers + length);
    //BubbleSort(numbers, length);

    map<int, int>result;
	int firstArr = numbers[0];
	int times = 1;
	bool isRepeat = false;
	for(int i = 1; i < length; ++i)
	{
		if(firstArr == numbers[i])
		{
			times++;
			isRepeat = true;
		}
		else
		{
			if(isRepeat)
			{
				result.insert(make_pair(firstArr, times));
				times = 1;
				isRepeat = false;
			}
			firstArr = numbers[i];
		}
	}
	if(isRepeat)
	{
		result.insert(make_pair(firstArr, times));
	}

	//遍历map
	auto map_it = result.cbegin();
	while(map_it != result.cend())
	{
		cout << map_it->first << ": " << map_it->second << " times" << endl;
		++ map_it;
	}

}