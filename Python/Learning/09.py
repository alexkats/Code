f = 0
i = 0

while (i < 10):
	if (i % 2 == 0):
		f = f + 4 / (i * 2 + 1)
	else:
		f = f - 4 / (i * 2 + 1)

	i += 1

print (f)	