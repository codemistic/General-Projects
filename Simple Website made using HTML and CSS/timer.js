// function greet()
//             {
//                 document.getElementById('container').innerHTML = container;
//             }
//             setTimeout(greet,5000);

// setTimeout(function(){
//     window.location.replace('css page.html');
//  }, 5000);

// function Redirect() 
//     {  
//         window.location="css page.html"; 
//     } 
//     document.write("You will be redirected to a new page in 5 seconds"); 
//     setTimeout('Redirect()', 5000);   

setTimeout(function(){
    window.location.href = 'css page.html';
    var executed = false;
    return function() {
        if (!executed) {
            executed = true;
        }
    };
 }, 5000);