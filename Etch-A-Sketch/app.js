const container = document.querySelector(".the-tiny");
const colors = document.querySelectorAll(".btn-color");
const pick = document.querySelector("#input-color");
const clear = document.querySelector(".clear");
var slider = document.querySelector("#sizeRange");
var color = "black";

function createGrid(gridNumber) {
  let gridArea = gridNumber ** 2;
  for (let i = 1; i <= gridArea; i++) {
    let gridItem = document.createElement("div");
    container.style.gridTemplateColumns = `repeat(${gridNumber},1fr)`;
    container.style.gridTemplateRows = `repeat(${gridNumber},1fr)`;
    container.insertAdjacentElement("beforeend", gridItem);
  }
  var gridPixels = container.querySelectorAll("div");
  gridPixels.forEach((gridPixel) =>
    gridPixel.addEventListener("mouseover", colorGrid)
  );
}

function colorGrid() {
  switch (color) {
    case "rainbow":
      this.style.backgroundColor = `hsl(${Math.random() * 360}, 100%, 50%)`;
      this.classList.remove("grey");
      break;
    case "grey":
      if (this.style.backgroundColor.match(/rgba/)) {
        console.log(this.style.backgroundColor);
        console.log(Number(this.style.backgroundColor.slice(-4,-1)));
        let currentOpacity = Number(this.style.backgroundColor.slice(-4, -1));
        if (currentOpacity <= 0.9) {
          this.style.backgroundColor = `rgba(0, 0, 0, ${currentOpacity + 0.1})`;
          this.classList.add("grey");
        }
      } else if (
        this.classList == "grey" &&
        this.style.backgroundColor == "rgb(0, 0, 0)"
      ) {
        return;
      } else {
        this.style.backgroundColor = "rgba(0, 0, 0, 0.1)";
      }
      break;
    case "eraser":
      this.style.backgroundColor = "#ffffff";
      this.classList.remove("grey");
      break;
    case "black":
      this.style.backgroundColor = "#000000";
      this.classList.remove("grey");
      break;
    default:
      this.style.backgroundColor = color;
      this.classList.remove("grey");
      break;
  }
}

function eraseAllColor() {
  var gridPixels = container.querySelectorAll("div");
  gridPixels.forEach((i) => (i.style.backgroundColor = "#ffffff"));
}

function changeColor(event) {
  switch (event.target.dataset.color) {
    case "rainbow":
      color = "rainbow";
      break;
    case "grey":
      color = "grey";
      break;
    case "eraser":
      color = "eraser";
      break;
    default:
      color = "black";
      break;
  }
}

function pixelSize() {
  let gridPixels = container.querySelectorAll("div");
  gridPixels.forEach((i) => i.remove());
  createGrid(slider.value);
}

function userColorSelection(event) {
  color = event.target.value;
}

createGrid(10);

clear.addEventListener("click", eraseAllColor);
colors.forEach((i) => i.addEventListener("click", changeColor));
slider.addEventListener("mouseup", pixelSize);
pick.addEventListener("change", userColorSelection, false);
pick.addEventListener("input", userColorSelection, false);
