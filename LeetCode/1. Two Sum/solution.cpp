	vector<int> res;

	unordered_set <int> seen;

	int target_left = 0;

	for (size_t i = 0; i < nums.size(); i++)
	{
		target_left = target - nums[i];

		if (seen.find(target_left) != seen.end())
		{
			res.push_back(i);
			break;
		}
		seen.insert(nums[i]);
	}

	for (size_t i = 0; i < nums.size(); i++)
	{
		if (target_left == nums[i])
		{
			res.push_back(i);
			break;
		}
	}
	return res;