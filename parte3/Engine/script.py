import re
import math


def calculaRaio(x,y):
	return math.sqrt(x*x+y*y)



f = open("config.xml",'r')
e = open("config2.xml",'w')

tempo = 20

for line in f:
	placeholder = '<translate time="' + str(tempo) + '" >\n'
	i = 0
	tempo += 30

	if(linha :=	re.search(r'\<translate X\=\"(-?\d+)\"\/\>', line)):
		if float(linha.group(1)) > 0:
			r = math.log(float(linha.group(1)))-8			
		else:
			r = float(linha.group(1))
			print(r)

		while(i<(2*math.pi)):
				
			x = r * round(math.cos(i), 6)
		
			z = r * round(math.sin(i), 6)

			i += math.pi / 6
			placeholder += '\t\t <point X="' + str(x) + '" Y="0" Z="' + str(z) + '"/>\n'

		placeholder += "\t</translate>\n"
		line = re.sub(rf'{linha.group(0)}', rf'{placeholder}', line)

	elif(linha := re.search(r'\<translate X\=\"(-?\d+)\" Y=\"(-?\d+)\"\/\>', line)):
		xInit = float(linha.group(1))
		yInit = float(linha.group(2))

		r = calculaRaio(xInit, yInit)

		while(i<(2*math.pi)):
			if tempo%3 == 0:
				x = r * round(math.cos(i), 6)
				y = r * round(math.sin(i), 6)
				z = 0
			elif tempo%4 == 0:
				x = r * round(math.cos(i), 6)
				y = 0
				z = r * round(math.sin(i), 6)
			else:
				x = 0
				y = r * round(math.cos(i), 6)
				z = r * round(math.sin(i), 6)

			i += math.pi / 6
			placeholder += '\t\t <point X="' + str(x) + '" Y="' + str(y) + '" Z="' + str(z) + '"/>\n'

		placeholder += "\t</translate>\n"
		line = re.sub(rf'{linha.group(0)}', rf'{placeholder}', line)

	e.write(line)
