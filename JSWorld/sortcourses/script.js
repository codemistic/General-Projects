const courses = [
  {
    name: "Complete ReactJS course",
    price: "2.3",
  },
  {
    name: "Complete Angular course",
    price: "2.1",
  },
  {
    name: "Complete MERN course",
    price: "2.7",
  },
  {
    name: "Complete C++ course",
    price: "2.8",
  },
  {
    name: "Django Course",
    price: "7.4",
  },
];

{
  /* <li class="list-group-item">
  Complete C++ course
  <span class="float-right">$ 2.8</span>;
</li>; */
}

function generateLIST() {
  const ul = document.querySelector(".list-group");
  ul.innerHTML = "";
  courses.forEach((course) => {
    const li = document.createElement("li");
    li.classList.add("list-group-item");

    const name = document.createTextNode(course.name);
    li.appendChild(name);

    const span = document.createElement("span");
    span.classList.add("float-right");
    const price = document.createTextNode("$ " + course.price);
    span.appendChild(price);

    li.appendChild(span);
    ul.appendChild(li);
  });
}

// generateLIST();

window.addEventListener("load", generateLIST);

const buttonA = document.querySelector(".AOrder");
const buttonB = document.querySelector(".DOrder");


buttonA.addEventListener("click", () => {
  courses.sort((a, b) => a.price - b.price);
  generateLIST();
});

buttonB.addEventListener("click", () => {
  courses.sort((a, b) => b.price - a.price);
  generateLIST();
});
