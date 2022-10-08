# Microsoft PowerShell script to run c and cpp codes in a new terminal
# Author: Shivam Saini

Function c{
    Param ($Name)
    $Name_Without_Extension = ($Name -Split "\.", -2)[0];
    gcc $Name -o "$($Name_Without_Extension).exe";
    Start-Process -FilePath "$($Name_Without_Extension).exe";
}

Function cpp{
    Param ($Name)
    $Name_Without_Extension = ($Name -Split "\.", -2)[0];
    gcc $Name -o "$($Name_Without_Extension).exe";
    Start-Process -FilePath "$($Name_Without_Extension).exe";
}