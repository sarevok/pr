set terminal png notransparent butt medium crop
set output "1p2f_proc.png"
set xrange [0:25000]
set yrange [0:7.5]
set xtic nomirror out 5000
set mxtics 5
set ytic scale 0 1,1
set title "2f1p - szybkie transputery"
set style fill solid
set key outside below
set size ratio -1500
plot "1p2f_proc.dat" every ::0::1 using 3:1:3:4:1:($1+0.5) title '1. faza komunikacji' with boxxyerrorbars lt rgbcolor"#00ff00" lw 0,\
"1p2f_proc.dat" every ::0::1 using 4:1:4:4:1:($1+0.5) notitle with boxxyerrorbars lt rgbcolor"#ffffff" lw 0,\
"1p2f_proc.dat" every ::0::1 using 7:1:7:8:1:($1+0.5) title '2. faza komunikacji' with boxxyerrorbars lt rgbcolor"#0000ff" lw 0,\
"1p2f_proc.dat" every ::0::1 using 8:1:8:8:1:($1+0.5) notitle with boxxyerrorbars lt rgbcolor"#ffffff" lw 0,\
"1p2f_proc.dat" every ::0:0:0:0 using 9:($1-1):9:10:($1-1):($1-0.5) notitle with boxxyerrorbars lt rgbcolor"#00ff00" lw 0,\
"1p2f_proc.dat" every ::0:0:0:0 using 6:($1-1):11:12:($1-1):($1-0.5) notitle with boxxyerrorbars lt rgbcolor"#0000ff" lw 0,\
"1p2f_proc.dat" using 2:($1-0.5):2:5:($1-0.5):($1) title '1. faza obliczen' with boxxyerrorbars lt rgbcolor"#ff0000" lw 0,\
"1p2f_proc.dat" every :::1 using 6:($1-0.5):6:13:($1-0.5):($1) title '2. faza obliczen' with boxxyerrorbars lt rgbcolor"#ffff00" lw 0,\
1.5 notitle with lines lt rgbcolor"#000000" lw 2,\
2.5 notitle with lines lt rgbcolor"#000000" lw 2,\
3.5 notitle with lines lt rgbcolor"#000000" lw 2,\
4.5 notitle with lines lt rgbcolor"#000000" lw 2,\
5.5 notitle with lines lt rgbcolor"#000000" lw 2,\
6.5 notitle with lines lt rgbcolor"#000000" lw 2
