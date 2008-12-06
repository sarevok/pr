#set terminal png notransparent medium crop
#set output "szeregowe_proc.png"
set terminal postscript eps
set output "szeregowe_proc.eps"
set xrange [0:46500]
set yrange [0.5:7.5]
set xtic nomirror out 5000
set mxtics 5
set ytic scale 0 1
set title "Szeregowe - szybkie procesory"
set style fill solid
set key outside below
set size ratio -1500
plot "szeregowe_proc.dat" using 2:($1-0.5):2:3:($1-0.5):($1+0.5) title 'Komunikacja' with boxxyerrorbars lt rgbcolor"#00ff00",\
"szeregowe_proc.dat" using 3:($1-0.5):3:4:($1-0.5):($1+0.5) title 'Komunikacja 2' with boxxyerrorbars lt rgbcolor"#0000ff",\
"szeregowe_proc.dat" using 4:($1-0.5):4:5:($1-0.5):($1+0.5) title 'Obliczenia' with boxxyerrorbars lt rgbcolor"#ff0000",\
1.5 notitle with lines lt rgbcolor"#000000" lw 2,\
2.5 notitle with lines lt rgbcolor"#000000" lw 2,\
3.5 notitle with lines lt rgbcolor"#000000" lw 2,\
4.5 notitle with lines lt rgbcolor"#000000" lw 2,\
5.5 notitle with lines lt rgbcolor"#000000" lw 2,\
6.5 notitle with lines lt rgbcolor"#000000" lw 2
