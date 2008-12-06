set terminal png notransparent medium crop
set output "2p1f_proc.png"
set xrange [0:30000]
set yrange [0:7.5]
set xtic nomirror out 5000
set mxtics 5
set ytic scale 0 1,1
set title "1f2p - szybkie transputery"
set style fill solid
set key outside below
set size ratio -1500
plot "2p1f_proc.dat" every ::0::1 using 3:1:3:4:1:($1+0.5) title 'Pierwsza porcja' with boxxyerrorbars lt rgbcolor"#00ff00",\
"2p1f_proc.dat" every ::0::0 using 4:1:4:5:1:($1+0.5) title 'Druga porcja' with boxxyerrorbars lt rgbcolor"#0000ff",\
"2p1f_proc.dat" every ::0:0:0:0 using 3:($1-1):3:6:($1-1):($1-0.5) notitle with boxxyerrorbars lt rgbcolor"#00ff00",\
"2p1f_proc.dat" every ::0:0:0:0 using 6:($1-1):6:7:($1-1):($1-0.5) notitle with boxxyerrorbars lt rgbcolor"#0000ff",\
"2p1f_proc.dat" using 2:($1-0.5):2:8:($1-0.5):($1) title 'Obliczenia' with boxxyerrorbars lt rgbcolor"#ff0000",\
1.5 notitle with lines lt rgbcolor"#000000" lw 2,\
2.5 notitle with lines lt rgbcolor"#000000" lw 2,\
3.5 notitle with lines lt rgbcolor"#000000" lw 2,\
4.5 notitle with lines lt rgbcolor"#000000" lw 2,\
5.5 notitle with lines lt rgbcolor"#000000" lw 2,\
6.5 notitle with lines lt rgbcolor"#000000" lw 2
