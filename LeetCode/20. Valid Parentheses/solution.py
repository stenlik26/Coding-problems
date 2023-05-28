def add_binary(s: str):
	brackets = []
	closing_br = {
		')' : '(',
		'}' : '{',
		']' : '['
	}

	for current in s:
		if current in closing_br.keys():
			if len(brackets) == 0:
				return False
			
			last_bracket = brackets.pop()

			if last_bracket != closing_br[current]:
				return False

		else:
			brackets.append(current)	

	return len(brackets) == 0