let side = 16;
let grid = document.querySelector(".grid");
let sideSize = document.querySelector(".sideSize");
let drawing = true;
let color = "#658CE6";
function createGrid(){
    for(let i=0; i<side; i++){
        let row = document.createElement('div');
        row.classList.add('row');
        for(let j=0; j<side; j++){
            let pixel = document.createElement('div');
            pixel.classList.add('pixel');
            pixel.addEventListener('click',()=>{
                drawing =  drawing==false? true: false;
                console.log(drawing);
            });
            pixel.addEventListener('mouseover',()=>{
                if(drawing){
                    pixel.style.backgroundColor = color;
                }
            })
            row.appendChild(pixel)
        }
        grid.appendChild(row);
    }
    // document.body.appendChild(grid);
}
function resetGrid(){
    grid.textContent=""
    createGrid();
}
createGrid();

let slider = document.querySelector("#sizeSlider");
slider.addEventListener('change',()=>{
    side = slider.value;
    if(side>100 || side<0) side = 100;
    sideSize.innerText = side;
    resetGrid();
});
slider.addEventListener('input',()=>{
    sideSize.innerText = slider.value;
});

let colorPicker = document.querySelector("#colorPicker");
colorPicker.addEventListener('input',()=>{color=colorPicker.value;});