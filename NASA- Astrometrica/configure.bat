@ECHO OFF

SET path=%~dp0%

REM system letter
REM %path:~0,2%

ECHO "update configuration files"
REM get sed-escaped Astrometrica directory
echo %path%| sed "s|\\|\\\\|g" > tmp
set /p EscapedPath= < tmp
del tmp

sed -e "s#\[\]\\Astrometrica\\#%EscapedPath%#" Settings\ARI-24.cfg.default > Settings\ARI-24.cfg
sed -e "s#\[\]\\Astrometrica\\#%EscapedPath%#" Settings\ARI-30.cfg.default > Settings\ARI-30.cfg
sed -e "s#\[\]\\Astrometrica\\#%EscapedPath%#" Settings\ARI-32.cfg.default > Settings\ARI-32.cfg
sed -e "s#\[\]\\Astrometrica\\#%EscapedPath%#" Settings\ARI-50.cfg.default > Settings\ARI-50.cfg
sed -e "s#\[\]\\Astrometrica\\#%EscapedPath%#" Settings\LCOGT-K91.cfg.default > Settings\LCOGT-K91.cfg
sed -e "s#\[\]\\Astrometrica\\#%EscapedPath%#" Settings\PS1.cfg.default > Settings\PS1.cfg
sed -e "s#\[\]\\Astrometrica\\#%EscapedPath%#" Settings\PS2.cfg.default > Settings\PS2.cfg
sed -e "s#\[\]\\Astrometrica\\#%EscapedPath%#" Settings\CSS-G96.cdg.default > Settings\CSS-G96.cdg
REM sed -e "s#\[\]\\Astrometrica\\#%EscapedPath%#" Settings\CSS-703.cdg.default > Settings\CSS-703.cdg
REM sed -e "s#\[\]\\Astrometrica\\#%EscapedPath%#" Settings\XingLong.cfg.default > Settings\XingLong.cfg
sed -e "s#\[\]\\Astrometrica\\#%EscapedPath%#" Astrometrica.cfg.default > Astrometrica.cfg

ECHO "update old configuration file"
sed -e "s#\[\]\\Astrometrica\\#%EscapedPath%#" Astrometrica.ini.default > Astrometrica.ini
copy "%path%Astrometrica.ini" "%USERPROFILE%\Local Settings\Application Data\Astrometrica\Astrometrica.ini"

ECHO "update the run file"
sed -e "s#\[\]\\Astrometrica\\#%EscapedPath%#" Astrometrica.bat.default > Astrometrica.bat

ECHO "cleanup"

del shortcut.vbs
del Settings\ARI-24.cfg.default
del Settings\ARI-30.cfg.default
del Settings\ARI-32.cfg.default
del Settings\PS1.cfg.default
del Settings\PS2.cfg.default
del Settings\XingLong.cfg.default
del Astrometrica.ini.default
del Astrometrica.cfg.default
del Astrometrica.bat.default
del sed.exe
del regex2.dll

@ECHO ON

pause