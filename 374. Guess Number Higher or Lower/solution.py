def guessNumber(n: int):
	currentHighest = n
	currentLowest = 1
	current_guess = (currentHighest + currentLowest) / 2
	guess_high = guess(math.ceil(current_guess))
	guess_low = guess(math.floor(current_guess))

	while guess_high != 0 or guess_low != 0:
		if guess_low == -1:
			currentHighest = math.ceil(current_guess)
		elif guess_high == -1:
			currentHighest = math.floor(current_guess)
		elif guess_low == 1:
			currentLowest = math.ceil(current_guess)
		elif guess_high == 1:
			currentLowest = math.floor(current_guess)
		current_guess = (currentHighest + currentLowest) / 2
		guess_high = guess(math.ceil(current_guess))
		guess_low = guess(math.floor(current_guess))


	if guess_high == 0:
		return math.ceil(current_guess)
	else:
		return math.floor(current_guess)