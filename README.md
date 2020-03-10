# SPO_Vaja2.1
Vaja pri predmetu SPO
Navodila s strani:
Napišite aplikacijo v programskem jeziku C, ki preko vhodnih argumentov prejme poljubne znake kodirane v kodnem sistemu unicode (X+221A) in jih pretvori v zapis UTF-8. Aplikacija mora končne rezultate izpisati v binarnem in hexadecimalnem številskem sistemu.
Uporaba kakršnih koli sistemskih knjižnic ni zaželjena.

Primer (znak za koren): unicode: X+221A (X+ - pomeni, da gre za 16-iško število)

UTF-8 binarno: 1110 0010 1000 1000 1001 1010 (presledki so za lažjo berljivost)

UTF-8 hex: E2889A

Pretvorbena tabela:

Območje kod unicode	Transformacijski format za UTF-8 (binarni zapis)
Od X'00 do X'7F	0xxx xxxx
Od X'80 do X'7FF	110x xxxx 10xx xxxx
Od X'800 do X'FFFF	1110 xxxx 10xx xxxx 10xx xxxx
x- predstavljajo mesta kamore je potrebno vnesti unicode vrednosti.

Postopek:

  unicode pretvorite v binarni zapis,
  binarni zapis vnesete v mesta označena z x,
  rezultat pretvorite v hex zapis.
