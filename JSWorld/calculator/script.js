const calculatorScreen = document.querySelector('.calculator-screen')
const numbers = document.querySelectorAll(".number")
const operators = document.querySelectorAll(".operator")
const equalSign = document.querySelector('.equal-sign')
const clearBtn = document.querySelector('.all-clear')
const decimal = document.querySelector('.decimal')
const percentage = document.querySelector('.percentage')


const updateScreen = (number) => {
    calculatorScreen.value = number
}


numbers.forEach((number) => {
    number.addEventListener("click", (event) => {
        inputNumber(event.target.value)
        updateScreen(currentInput)
    })
})

let prevInput = '0'
let calculationOperator = ''
let currentInput = '0'

const inputNumber = (number) => {
    if (currentInput == 0) {
        currentInput = number
    } else {
        currentInput += number
    }
}


operators.forEach((operator) => {
    operator.addEventListener("click", (event) => {
        inputOperator(event.target.value)
    })
})

const inputOperator = (operator) => {
    if (calculationOperator === '') {
        prevInput = currentInput
    }
    calculationOperator = operator
    currentInput = '0'
}


equalSign.addEventListener('click', () => {
    calculate()
    updateScreen(currentInput)
})

const calculate = () => {
    let result = 0
    switch (calculationOperator) {
        case '+':
            result = parseFloat(prevInput) + parseFloat(currentInput)
            break
        case '-':
            result = parseFloat(prevInput) - parseFloat(currentInput)
            break
        case '*':
            result = parseFloat(prevInput) * parseFloat(currentInput)
            break
        case '/':
            result = parseFloat(prevInput) / parseFloat(currentInput)
            break
        default:
            return
    }
    currentInput = result
    calculationOperator = ''
}


clearBtn.addEventListener('click', () => {
    clearAll()
    updateScreen(currentInput)
})

const clearAll = () => {
    prevInput = '0'
    calculationOperator = ''
    currentInput = '0'
}


decimal.addEventListener('click', (event) => {
    inputDecimal(event.target.value)
    updateScreen(currentInput)
})

const inputDecimal = (dot) => {
    if (currentInput.includes('.')) {
        return
    }
    currentInput += dot
}


percentage.addEventListener('click', (event) => {
    getPercentage()
    updateScreen(currentInput)
})

const getPercentage = () => {
    currentInput = currentInput / 100
}