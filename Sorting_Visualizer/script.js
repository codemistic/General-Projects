const container = document.querySelector(".data-container");

function generatebars(num = 20) 									// Function to generate bars
{
	for (let i = 0; i < num; i += 1) 								// For loop to generate 20 bars
	{
		const value = Math.floor(Math.random() * 100) + 1;			// To generate random values from 1 to 100
		const bar = document.createElement("div");					// To create element "div"
		bar.classList.add("bar");								    // To add class "bar" to "div"
		bar.style.height = `${value * 3}px`;						// Provide height to the bar
		bar.style.transform = `translateX(${i * 30}px)`;			// Translate the bar towards positive X axis
		const barLabel = document.createElement("label");			// To create element "label"
		barLabel.classList.add("bar__id");							// To add class "bar_id" to "label"
		barLabel.innerHTML = value;	    							// Assign value to "label"
		bar.appendChild(barLabel);									// Append "Label" to "div"
		container.appendChild(bar);									// Append "div" to "data-container div"
	}
}

generatebars();					// Call "generatebars()" function

function generate() {			// Function to generate new random array
	window.location.reload();
}

function disable() 				// Function to disable the button
{
	// To disable the button "Generate New Array"
	document.getElementById("Button1").disabled = true;
	document.getElementById("Button1").style.backgroundColor = "#B2AB8C;";

	// To disable the button "Shell Sort"
	document.getElementById("Button2").disabled = true;
	document.getElementById("Button2").style.backgroundColor = "#B2AB8C";
}

function enable()				// function to enable the button
{
	// To enable the button "Generate New Array" after final(sorted)
	document.getElementById("Button1").disabled = false;
	document.getElementById("Button1").style.backgroundColor = "#FFE268";
	document.getElementById("Button1").style.font = "#black";


	// To enable the button "Shell Sort" after final(sorted)
	document.getElementById("Button2").disabled = false;
	document.getElementById("Button2").style.backgroundColor = "#FFE268";	
	document.getElementById("Button1").style.font = "#black";
}

async function ShellSort(delay = 100) {								// Shell Sort
	let bars = document.querySelectorAll(".bar");
	for (var i = 10; i > 0; i = Math.floor(i / 2)) {			    // To pause the execution of code for 300 milliseconds
		await new Promise((resolve) => setTimeout(() => {resolve();}, 100));

		for (var j = i; j < 20; j++) {
			var temp = parseInt(bars[j].childNodes[0].innerHTML), k;
			var temp1 = bars[j].style.height;
			var temp2 = bars[j].childNodes[0].innerText;
			for (k = j; k >= i && parseInt(bars[k - i].childNodes[0].innerHTML) > temp; k -= i) 
			{
				bars[k].style.height = bars[k - i].style.height;
				bars[k].childNodes[0].innerText = bars[k - i].childNodes[0].innerText;
				await new Promise((resolve) => setTimeout(() => {resolve();}, 100));
			}
			
			// providing different colour to jth and kth bar
			bars[j].style.backgroundColor = "#39A6A3";
			bars[k].style.backgroundColor = "#39A6A3";
			bars[k].style.height = temp1;
			bars[k].childNodes[0].innerText = temp2;

			await new Promise((resolve) => setTimeout(() => {resolve();}, 100));

			// providing different colour to jth and kth bar
			bars[j].style.backgroundColor = "#014955";
			bars[k].style.backgroundColor = "#014955";

			await new Promise((resolve) => setTimeout(() => {resolve();}, 100));
		}
	}
	for (var x = 0; x < 20; x++) 
		bars[x].style.backgroundColor = "#FFC93C";

	enable();
}

async function SelectionSort(delay = 300) {				//selection sort
	let bars = document.querySelectorAll(".bar");
	for (var i = 0; i < bars.length; i += 1) {
		min_idx = i;

		bars[i].style.backgroundColor = "#014955";
		for (var j = i + 1; j < bars.length; j += 1) 
		{
			bars[j].style.backgroundColor = "#39A6A3";
			await new Promise((resolve) => setTimeout(() => {resolve();}, 100));

			var val1 = parseInt(bars[j].childNodes[0].innerHTML);
			var val2 = parseInt(bars[min_idx].childNodes[0].innerHTML);
			
			if (val1 < val2) {
				if (min_idx !== i) 
					bars[min_idx].style.backgroundColor = "#014955";
				min_idx = j;
			} else 
				bars[j].style.backgroundColor = "#014955";
		}

		var temp1 = bars[min_idx].style.height;
		var temp2 = bars[min_idx].childNodes[0].innerText;
		bars[min_idx].style.height = bars[i].style.height;
		bars[i].style.height = temp1;
		bars[min_idx].childNodes[0].innerText = bars[i].childNodes[0].innerText;
		bars[i].childNodes[0].innerText = temp2;
		
		await new Promise((resolve) => setTimeout(() => {resolve();}, 100));

		bars[min_idx].style.backgroundColor = "#FFE268";
		bars[i].style.backgroundColor = "#014955";
	}
	for (var x = 0; x < 20; x++) 
		bars[x].style.backgroundColor = "#FFC93C";

	enable();
}

async function InsertionSort(delay = 100) {			// insertion sort
	let bars = document.querySelectorAll(".bar");

	bars[0].style.backgroundColor = "#014955";
	for (var i = 1; i < bars.length; i += 1) {
		var j = i - 1;
		var key = parseInt(bars[i].childNodes[0].innerHTML);
		var height = bars[i].style.height;
		var barval=document.getElementById("ele")
		bars[i].style.backgroundColor = "#39A6A3";
		await new Promise((resolve) => setTimeout(() => {resolve();}, 100));

		while (j >= 0 && parseInt(bars[j].childNodes[0].innerHTML) > key) 
		{
			bars[j].style.backgroundColor = "#39A6A3";
			bars[j + 1].style.height = bars[j].style.height;
			bars[j + 1].childNodes[0].innerText =
			bars[j].childNodes[0].innerText;
			j = j-1;

			await new Promise((resolve) => setTimeout(() => {resolve();}, 100));	
			for(var k=i;k>=0;k--)
				bars[k].style.backgroundColor = "#014955";
		}

		bars[j + 1].style.height = height;
		bars[j + 1].childNodes[0].innerHTML = key;
		
		await new Promise((resolve) => setTimeout(() => {resolve();}, 100));
		bars[i].style.backgroundColor = "#FFE268";
	}
		for (var x = 0; x < 20; x++) 
		bars[x].style.backgroundColor = "#FFC93C";

	enable();
}

function swap(el1, el2) {
	return new Promise((resolve) => {
		var temp = el1.style.transform;
		el1.style.transform = el2.style.transform;
		el2.style.transform = temp;

		window.requestAnimationFrame(function() {
			setTimeout(() => {container.insertBefore(el2, el1); resolve();}, 100);});
		});
}

async function BubbleSort(delay = 100) {					//// BubbleSort function
	let bars = document.querySelectorAll(".bar");
	bars[0].style.backgroundColor = "#014955";

	for (var i = 0; i < bars.length; i += 1) {
		for (var j = 0; j < bars.length - i - 1; j += 1) {
			bars[j].style.backgroundColor = "#39A6A3";
			bars[j + 1].style.backgroundColor = "#39A6A3";
			await new Promise((resolve) => setTimeout(() => {resolve();}, 100));
			
			var value1 = Number(bars[j].childNodes[0].innerHTML);
			var value2 = Number(bars[j + 1].childNodes[0].innerHTML);

			if (value1 > value2) {
				await swap(bars[j], bars[j + 1]);
				bars = document.querySelectorAll(".bar");
			}
			bars[j].style.backgroundColor = "#014955";
			bars[j + 1].style.backgroundColor = "#014955";
		}

		bars[bars.length - i - 1].style.backgroundColor = "#FFE268";
	}
	for (var x = 0; x < 20; x++) 
		bars[x].style.backgroundColor = "#FFC93C";

	enable();
}

async function Heapify(n, i) {
	let bars = document.querySelectorAll(".bar");
	var largest = i; // Initialize largest as root
	var l = 2 * i + 1; // left = 2*i + 1
	var r = 2 * i + 2; // right = 2*i + 2

	if (l < n && Number(bars[l].childNodes[0].innerHTML) > Number(bars[largest].childNodes[0].innerHTML))
		largest = l;

	if (r < n && Number(bars[r].childNodes[0].innerHTML) > Number(bars[largest].childNodes[0].innerHTML))
		largest = r;

	if (largest != i) {
		var temp1 = bars[i].style.height;
		var temp2 = bars[i].childNodes[0].innerText;
		bars[i].style.height = bars[largest].style.height;
		bars[i].style.backgroundColor = "#014955";
		bars[largest].style.height = temp1;
		bars[i].childNodes[0].innerText =
		bars[largest].childNodes[0].innerText;
		bars[largest].childNodes[0].innerText = temp2;

		await new Promise((resolve) => setTimeout(() => {resolve();}, 250));
		await Heapify(n, largest);
	}
}

async function HeapSort(n) {			//heap sort
	let bars = document.querySelectorAll(".bar");

	for (var i = n / 2 - 1; i >= 0; i--) 
		await Heapify(n, i);

	for (var i = n - 1; i > 0; i--) {
		var temp1 = bars[i].style.height;
		var temp2 = bars[i].childNodes[0].innerText;
		bars[i].style.height = bars[0].style.height;
		bars[i].style.backgroundColor = "#FFE268";
		bars[0].style.height = temp1;
		bars[i].childNodes[0].innerText = bars[0].childNodes[0].innerText;
		bars[0].childNodes[0].innerText = temp2;

		await new Promise((resolve) => setTimeout(() => {resolve();}, 250));
		await Heapify(i, 0);
	}
	for (var x = 0; x < 20; x++) 
		bars[x].style.backgroundColor = "#FFC93C";

	enable();
}

async function lometo_partition(l, r, delay = 100) {
	let bars = document.querySelectorAll(".bar");

	var pivot = Number(bars[r].childNodes[0].innerHTML);
	var i = l - 1;
	bars[r].style.backgroundColor = "#FFE268";

	document.getElementsByClassName("range")[0].innerText = `[${l},${r}]`;

	for (var j = l; j <= r - 1; j++) {
		bars[j].style.backgroundColor = "#FFE268";
		await new Promise((resolve) => setTimeout(() => {resolve();}, 100));

		var value = Number(bars[j].childNodes[0].innerHTML);

		if (value < pivot) {
			i++;
			var temp1 = bars[i].style.height;
			var temp2 = bars[i].childNodes[0].innerText;
			bars[i].style.height = bars[j].style.height;
			bars[j].style.height = temp1;
			bars[i].childNodes[0].innerText = bars[j].childNodes[0].innerText;
			bars[j].childNodes[0].innerText = temp2;
			bars[i].style.backgroundColor = "#014955";
			if (i != j) 
				bars[j].style.backgroundColor = "#39A6A3";
	
			await new Promise((resolve) => setTimeout(() => {resolve();}, delay));
		} else 
			bars[j].style.backgroundColor = "#39A6A3";
	}
		// Swapping the ith with pivot element
		i++;
		var temp1 = bars[i].style.height;
		var temp2 = bars[i].childNodes[0].innerText;
		bars[i].style.height = bars[r].style.height;
		bars[r].style.height = temp1;
		bars[i].childNodes[0].innerText = bars[r].childNodes[0].innerText;
		bars[r].childNodes[0].innerText = temp2;
		bars[r].style.backgroundColor = "#39A6A3";
		bars[i].style.backgroundColor = "#FFE268";

		await new Promise((resolve) => setTimeout(() => {resolve();}, delay * 3));

		document.getElementsByClassName("range")[0].innerText = "";
		for (var k = 0; k < 20; k++)
			bars[k].style.backgroundColor = "#FFC93C";
		return i;
}

async function QuickSort(l, r, delay = 100) {
	if (l < r) {
		var pivot_idx = await lometo_partition(l, r);
		await QuickSort(l, pivot_idx - 1);
		await QuickSort(pivot_idx + 1, r);
	}
}
