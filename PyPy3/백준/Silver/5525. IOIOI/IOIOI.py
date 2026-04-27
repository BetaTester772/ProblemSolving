def kmp_table(pattern):
    lps = [0] * len(pattern)
    j = 0
    
    for i in range(1, len(pattern)):
        while j > 0 and pattern[i] != pattern[j]:
            j = lps[j - 1]
        if pattern[i] == pattern[j]:
            j += 1
            lps[i] = j
    return lps


def kmp_search(text, pattern):
    lps = kmp_table(pattern)
    i = j = 0
    count = 0

    while i < len(text):
        if text[i] == pattern[j]:
            i += 1
            j += 1
            if j == len(pattern):
                count += 1
                j = lps[j - 1]
        else:
            if j > 0:
                j = lps[j - 1]
            else:
                i += 1
    return count

N = int(input())
pattern = "I"+"OI"*N
M = int(input())
text = input()
print(kmp_search(text, pattern))
