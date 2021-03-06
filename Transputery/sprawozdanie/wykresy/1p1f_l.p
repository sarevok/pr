set terminal png notransparent medium crop
set output "1p1f_lacza.png"
set xrange [0:30000]
set yrange [0:7.5]
set xtic nomirror out 5000
set mxtics 5
set ytic scale 0 1,1
set title "1f1p - szybkie lacza"
set style fill solid
set key outside below
set size ratio -1500
plot "1p1f_lacza.dat" every ::0::1 using 2:1:2:3:1:($1+0.5) title 'Komunikacja' with boxxyerrorbars lt rgbcolor"#00ff00",\
"1p1f_lacza.dat" every ::0:0:0:0 using 2:($1-1):2:4:($1-1):($1-0.5) title 'Komunikacja_2' with boxxyerrorbars lt rgbcolor"#0000ff",\
"1p1f_lacza.dat" using 2:($1-0.5):2:5:($1-0.5):($1) title 'Obliczenia' with boxxyerrorbars lt rgbcolor"#ff0000",\
1.5 notitle with lines lt rgbcolor"#000000" lw 2,\
2.5 notitle with lines lt rgbcolor"#000000" lw 2,\
3.5 notitle with lines lt rgbcolor"#000000" lw 2,\
4.5 notitle with lines lt rgbcolor"#000000" lw 2,\
5.5 notitle with lines lt rgbcolor"#000000" lw 2,\
6.5 notitle with lines lt rgbcolor"#000000" lw 2
