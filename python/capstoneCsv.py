import csv

f = open('Courses.csv', 'r' , encoding='utf-8')
rdr = csv.reader(f)

ff = open('newCourses.csv', 'w', encoding='utf-8', newline = '')
wr = csv.writer(ff)

for line in rdr:
    newline = line[2:]
    wr.writerow(newline)
    print(newline)
f.close()
ff.close()
