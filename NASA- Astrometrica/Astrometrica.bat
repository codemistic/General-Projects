cd "E:\NASA\"

curl --insecure "https://minorplanetcenter.net/iau/MPCORB/MPCORB.DAT.gz" -o "MPCORB.DAT.gz"

gzip -d -f MPCORB.DAT.gz

move /Y MPCORB.DAT Catalogs

Astrometrica.exe

exit
