
// global constants and variables
const MAX_BAR_HEIGHT = 500;
const RED = "red";
const GREEN = "green";
const YELLOW = "yellow";
var deviceWidth = $(".barsContainer").width();  // since the width of the bars container is always 100%;
var numBars = 100;
var barWidth = (deviceWidth / numBars);
var speed = 0;
var arr = [];
var itmd = []; // intermediate array for merge sort


updateSlider();
displayRandomBars();


// fills random values in arr
function populateArray() {
    arr = [];
    for (var i = 0; i < numBars; ++i) {
        arr[i] = Math.floor(Math.random() * MAX_BAR_HEIGHT);
    }
}

// renders the bars on the screen with height corresponding to values in arr
async function renderBars() {
    let str = "";
    for (var i = 0; i < numBars; ++i) {
        let barHeight = arr[i];
        str += `<div class="bar" style="width:${barWidth}px; height: ${barHeight}px "> </div>`;
    }
    $(".barsContainer").html(str);
}

// renders the bars on the screen with height corresponding to values in arr, 
// changes colour of the bars at position a, b and c to col1, col2 and col3 respectively
async function renderColouredBars(a, b, c, col1, col2, col3) {
    let str = "";
    for (var i = 0; i < numBars; ++i) {
        let barHeight = arr[i];
        if (i === a) {
            str += `<div class="bar ${col1}Bar" style="width:${barWidth}px; height: ${barHeight}px "> </div>`;
        } else if (i === b) {
            str += `<div class="bar ${col2}Bar" style="width:${barWidth}px; height: ${barHeight}px "> </div>`;
        } else if (i === c) {
            str += `<div class="bar ${col3}Bar" style="width:${barWidth}px; height: ${barHeight}px "> </div>`;
        } else {
            str += `<div class="bar" style="width:${barWidth}px; height: ${barHeight}px "> </div>`;
        }
    }
    $(".barsContainer").html(str);
}


// renders the bars on the screen with height corresponding to values in arr, 
// changes colour of the bars at position a and b to red
async function render2RedBars(a, b) {
    let str = "";
    for (var i = 0; i < numBars; ++i) {
        let barHeight = arr[i];
        if (i === a || i === b) {
            str += `<div class="bar redBar" style="width:${barWidth}px; height: ${barHeight}px "> </div>`;
        } else {
            str += `<div class="bar" style="width:${barWidth}px; height: ${barHeight}px "> </div>`;
        }
    }
    $(".barsContainer").html(str);
}


// populates the array with fresh random values and then renders the bars with corresponding heights
function displayRandomBars() {
    populateArray();
    renderBars();
}

/////////////////////////////////// Event Listeners  ///////////////////////////////////

// click listener to generate random array
$("#numGenerator").on("click", displayRandomBars);
$("#sortBtn").on("click", () => {
    const option = $("#sortType").val();
    switch (option) {
        case "bubble":
            bubbleSort();
            break;
        case "insertion":
            insertionSort();
            break;
        case "selection":
            selectionSort();
            break;
        case "merge":
            mergeSortWithAnimation();
            break;
        case "quick":
            quickSortWithAnimation();
            break;
        default: alert("Please select a sorting option");
    }
});

// changes the number of bars according to the given input
$("#barCount").on("change", () => {
    numBars = $("#barCount").val();
    $("#numBarLabel").text(numBars);
    barWidth = (deviceWidth / numBars);
    displayRandomBars();
});

// changes the speed according to the given input
$("#sortingSpeed").on("change", () => {
    speed = $("#sortingSpeed").attr("max") - $("#sortingSpeed").val();
    if (speed === 100) {
        $("#speedLabel").text("Slowest");
    } else if (speed < 100 && speed > 70) {
        $("#speedLabel").text("Slow");
    } else if (speed <= 70 && speed > 30) {
        $("#speedLabel").text("Medium");
    } else if (speed <= 30 && speed > 0) {
        $("#speedLabel").text("Fast");
    } else if (speed === 0) {
        $("#speedLabel").text("Fastest");
    }
});

// sets the range of numBar slider according to the deviceWidth
function updateSlider() {
    if (deviceWidth < 912) {
        setBarRanges(50, 20, 100);
    } else {
        setBarRanges(100, 50, 300);
    }
    $("#barCount").attr("value", numBars);
    $("#numBarLabel").text($("#barCount").attr("value"));
    barWidth = (deviceWidth / numBars);
}

// helper for updateSlider
function setBarRanges(numOfBars, min, max) {
    numBars = numOfBars;
    $("#minBars").text(min);
    $("#maxBars").text(max);
    $("#barCount").attr("min", String(min));
    $("#barCount").attr("max", String(max));
}

// adjusts the bar widths when the screen is resized
$(window).resize(function () {
    deviceWidth = $(".barsContainer").width();
    barWidth = (deviceWidth / numBars);
    renderBars();
});


// renders all the bars in red colour then changes them back to white after 600ms
async function animateBars() {
    let str = "";
    for (var i = 0; i < numBars; ++i) {
        let barHeight = arr[i];
        str += `<div class="bar redBar" style="width:${barWidth}px; height: ${barHeight}px "></div>`;
        $(".barsContainer").html(str);
        await timer(0);
    }
    await timer(600);
    renderBars();
}

// Can be used if machine is fast enough
// To colour each bar red one by one

// async function animateBars() {
//     for (var i = 0; i < numBars; ++i) {
//         let str = "";
//         for (let j = 0; j <= i; ++j) {
//             let barHeight = arr[j];
//             str += `<div class="bar redBar" style="width:${barWidth}px; height: ${barHeight}px "></div>`;
//             $(".barsContainer").html(str);
//         }
//         for (let k = i + 1; k < numBars; ++k) {
//             let barHeight = arr[k];
//             str += `<div class="bar" style="width:${barWidth}px; height: ${barHeight}px "></div>`;
//             $(".barsContainer").html(str);
//         }
//         await timer(0);
//     }
//     await timer(600);
//     renderBars();
// }


///////////////////////////// Sorting Algorithms ////////////////////////////

// sorts arr in descending order using bubble sort
async function bubbleSort() {
    let t = 0;
    for (var i = 0; i < numBars; ++i) {
        for (var j = 0; j < numBars - 1; ++j) {
            if (arr[j] < arr[j + 1]) {
                await timer(0);
                render2RedBars(j, j + 1);
                t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
                await timer(speed);
                render2RedBars(j, j + 1);
            }
        }
    }
    animateBars();
}


// sorts arr in descending order using insertion sort
async function insertionSort() {
    for (let i = 1; i < numBars; ++i) {
        let x = arr[i];
        let j = i;
        // pushes the element at ith position backwards until a larger element is found
        while (x > arr[j - 1] && (j > 0)) {
            arr[j] = arr[j - 1];
            arr[j - 1] = x;
            j--;
            await timer(speed);
            renderColouredBars(i, i, j, YELLOW, YELLOW, RED);
        }
        arr[j] = x;
    }
    animateBars();
}

// sorts arr in descending order using selection sort
async function selectionSort() {
    for (let i = 0; i < numBars - 1; ++i) {
        let x = i;
        let j = i;
        for (j = i + 1; j < numBars; ++j) {
            if (arr[j] > arr[x]) {
                x = j;
            }
            await timer(speed);
            renderColouredBars(i, x, j, YELLOW, GREEN, RED);
        }
        let t = arr[x];
        arr[x] = arr[i];
        arr[i] = t;
    }
    animateBars();
}

// sorts arr in descending order using merge sort
async function mergeSort(start, end) {
    // merges 2 the arrays into one sorted array
    async function mergeArray(start, end) {
        let mid = parseInt((start + end) >> 1);
        let start1 = start, start2 = mid + 1
        let end1 = mid, end2 = end

        // Initial index of merged subarray
        let index = start

        while (start1 <= end1 && start2 <= end2) {
            if (arr[start1] >= arr[start2]) {
                itmd[index] = arr[start1]
                index = index + 1
                start1 = start1 + 1;
                await timer(speed);
                render2RedBars(start1, index);
            }
            else if (arr[start1] < arr[start2]) {
                itmd[index] = arr[start2]
                index = index + 1
                start2 = start2 + 1;
                await timer(speed);
                render2RedBars(start2, index);
            }
        }

        // Copy the remaining elements of
        // arr[], if there are any
        while (start1 <= end1) {
            itmd[index] = arr[start1]
            index = index + 1
            start1 = start1 + 1;
            await timer(speed);
            render2RedBars(start1, index);
        }

        while (start2 <= end2) {
            itmd[index] = arr[start2]
            index = index + 1
            start2 = start2 + 1;
            await timer(speed);
            render2RedBars(index, start2);
        }

        index = start
        while (index <= end) {
            arr[index] = itmd[index];
            index++;
            await timer(speed);
            render2RedBars(index, index);
        }
    }

    // main mergeSort function
    if (start < end) {
        let mid = parseInt((start + end) >> 1);
        await mergeSort(start, mid);
        await mergeSort(mid + 1, end);
        await mergeArray(start, end);
        await timer(speed);
        renderColouredBars(start, mid, end, RED, RED, RED);
    }
}


// first performs the mergeSort funtion and them animates the bars
async function mergeSortWithAnimation() {
    await mergeSort(0, arr.length - 1);
    animateBars();
}

// sorts arr in descending order using quick sort
async function quickSort(start = 0, end = arr.length - 1) {
    // swaps the values at i and j in arr
    async function swap(i, j) {
        const t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }

    // moves all elements smaller than the value of the pivot to the left and 
    // all element of greater value than the pivot to the right of the actual pivot index and
    // returns the actual pivot index in the sorted array
    async function pivotFinder(start = 0, end = arr.length - 1) {
        const pivot = arr[start];
        let pivotIndx = start;
        for (let i = start + 1; i <= end; i++) {
            if (arr[i] > pivot) {
                pivotIndx++;
                await swap(pivotIndx, i);
            }
            await timer(speed);
            renderColouredBars(i, pivotIndx, start, RED, GREEN, YELLOW);
        }
        await swap(pivotIndx, start);
        return pivotIndx;
    }

    // main quick sort logic
    if (start < end) {
        const pivot = await pivotFinder(start, end);
        await quickSort(start, pivot - 1);
        await quickSort(pivot + 1, end);
    }
}

// first performs the quickSort funtion and them animates the bars
async function quickSortWithAnimation() {
    await quickSort();
    animateBars();
}

// adds delay of given milliseconds
function timer(ms) {
    return new Promise(res => setTimeout(res, ms));
}