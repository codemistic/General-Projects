var add = document.getElementById('add');
var removeAll = document.getElementById('removeall');
var list = document.getElementById('list');

removeAll.onclick = function(){
    list.innerHTML ='';
}

add.onclick = function(){
    addlis(list);
    document.getElementById('userinput').value ='';
    document.getElementById('userinput').focus();
    
}

function addlis(targetUl){
    var inputText = document.getElementById('userinput').value;
    var li = document.createElement('li');
    var textNode = document.createTextNode(inputText + '');
    var removeButton =document.createElement('button');
    
    // removeButton.style.padding="20px";


    
    if(inputText !== ''){
        removeButton.style.fontSize="20px";
        removeButton.style.marginLeft="8px";
    removeButton.style.paddingLeft="10px";
    removeButton.style.paddingRight="10px";


        removeButton.className='btn btn-xs btn-danger';
        removeButton.innerHTML ='&times;' ;
        removeButton.setAttribute('onclick','removeMe(this)')
        
        li.appendChild(textNode);
        li.appendChild(removeButton);
        targetUl.appendChild(li);
    } else{
        alert('Please enter a TODO')
    }
}

function removeMe(item){
    var p = item.parentElement;
    p.parentElement.removeChild(p);
}












