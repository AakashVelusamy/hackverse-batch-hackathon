limit = int(input())
tRunes = input().strip()
vRunes = [int(x) for x in tRunes.split() if x.strip()]
maxn = 0
n = len(vRunes)
for i in range(n - 2):
    if vRunes[i] + vRunes[i + 2] == limit:
        maxn = max(vRunes[i] + vRunes[i + 2], maxn)
    if vRunes[i] == limit:
        maxn = max(vRunes[i], maxn)
if n > 2 and vRunes[n - 2] == limit:
    maxn = max(vRunes[n - 2], maxn)
if n > 1 and vRunes[n - 1] == limit:
    maxn = max(vRunes[n - 1], maxn)
print(maxn)

