class Solution(object):
    def findAndReplacePattern(self, words, pattern):
        """
        :type words: List[str]
        :type pattern: str
        :rtype: List[str]
        """
        if len(pattern) == 1 and len(words[0]) == 1:
            return words
        wordHashMap = [0]*26
        patternHashMap = [0]*26
        patternsList = []
        for word in words:
            isPermutation = True
            wordHashMap = [0]*26
            patternHashMap = [0]*26
            for i in range(1,len(word)):
                currentWordAscii = self.charIndex(word[i])
                previousWordAscii = self.charIndex(word[i-1])
                currentPatternAscii = self.charIndex(pattern[i])
                previousPatternAscii = self.charIndex(pattern[i-1])
                
                wordHashMap[currentWordAscii] += 1
                wordHashMap[previousWordAscii] += 1
                patternHashMap[currentPatternAscii] += 1
                patternHashMap[previousPatternAscii] += 1
                
                if wordHashMap[currentWordAscii] == patternHashMap[currentPatternAscii] and wordHashMap[previousWordAscii] ==           patternHashMap[previousPatternAscii]:
                    if word[i-1] != word[i] and pattern[i-1] != pattern[i]:
                        continue
                    elif word[i-1] == word[i] and pattern[i-1] == pattern[i]:
                        continue
                    else:
                        isPermutation = False
                        break
                else:
                    isPermutation = False
                    break
            if isPermutation:
                patternsList.append(word)
        return patternsList
    
    def charIndex(self, character):
        return ord(character) - 97


if __name__ == '__main__':
    words = ["abc","deq","mee","aqq","dkd","ccc"]
    pattern = "abb"
    obj = Solution()
    print(obj.findAndReplacePattern(words, pattern))