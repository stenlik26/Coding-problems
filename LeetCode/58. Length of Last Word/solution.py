def lengthOfLastWord(self, s: str) -> int:
    s = s.strip()
    print(s)
    s = s.replace(" ", "-")
    words = s.split('-')
    maxlen = len(words[0])
    for word in words:
        temp = len(word)
        if temp == 0:
            words.remove(word)

    return len(words[len(words) - 1])