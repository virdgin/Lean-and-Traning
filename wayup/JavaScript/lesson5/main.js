const option1 = document.querySelector('.option1'),
    option2 = document.querySelector('.option2'),
    option3 = document.querySelector('.option3'),
    option4 = document.querySelector('.option4');

const optionElements = document.querySelectorAll('.option');

const question = document.getElementById('question');

const numberOfQuestion = document.getElementById('number-of-question'),
    numberOfAllQuestion = document.getElementById('number-of-all-questions');

let indexOfQuestion,
    indexOfPage = 0;

const answersTracker = document.getElementById('answers-tracker');

const btnNext = document.getElementById('btn-next'),
    btnTryAgain = document.getElementById('btn-try-again')

let score = 0;

const correctAnswer = document.getElementById('correct-answer'),
    numberOfAllQuestion2 = document.getElementById('number-of-all-questions-2');

const questions = [
    {
        question: 'Как в JavaScript вычислить процент от числа?',
        options: [
            'Так в JavaScript нельзя селать',
            'Оператор : %',
            'Умножить на кол-во процентов и разделить на 100',
            'Вызвать метод findPrecent()',
        ],
        rightAnswer: 2
    },
    {
        question: 'Результат выражения "13" + 7',
        options: [
            '20',
            '137',
            'underfined',
            'error',
        ],
        rightAnswer: 1
    },
    {
        question: 'На JavaScript нельзя писать: ',
        options: [
            'Игры',
            'Скрипты для сайтов',
            'Десктопные приложения',
            'Плохо',
        ],
        rightAnswer: 3
    },
]

numberOfAllQuestion.innerHTML = questions.length;

const load = () => {
    question.innerHTML = questions[indexOfQuestion].question;

    option1.innerHTML = questions[indexOfQuestion].options[0];
    option2.innerHTML = questions[indexOfQuestion].options[1];
    option3.innerHTML = questions[indexOfQuestion].options[2];
    option4.innerHTML = questions[indexOfQuestion].options[3];

    numberOfQuestion.innerHTML = indexOfPage + 1;
    indexOfPage++;
};

let completedAnswer = [];

const randomQuestion = () => {
    let randomNumber = Math.floor(Math.random() * questions.length);
    let hitDuplicate = false;

    if (indexOfPage == questions.length) {
        quizOver();
    } else {
        if (completedAnswer.length > 0) {
            completedAnswer.forEach(item => {
                if (item == randomNumber) {
                    hitDuplicate = true;
                }
            });
            if (hitDuplicate) {
                randomQuestion();
            } else {
                indexOfQuestion = randomNumber;
                load();
            }
        }
        if (completedAnswer.length == 0) {
            indexOfQuestion = randomNumber;
            load();
        }
    }
    completedAnswer.push(indexOfQuestion);
};

const checkAnswer = el => {
    if (el.target.dataset.id == questions[indexOfQuestion].rightAnswer) {
        el.target.classList.add('correct');
        updateAnswerTracker('correct');
        score++;
    } else {
        el.target.classList.add('wrong');
        updateAnswerTracker('wrong');
    }
    disableOptions();
}
for (option of optionElements) {
    option.addEventListener('click', e => checkAnswer(e));
}

const disableOptions = () => {
    optionElements.forEach(item => {
        item.classList.add('disabled');
        if (item.dataset.id == questions[indexOfQuestion].rightAnswer) {
            item.classList.add('correct');
        }
    })
}

const enableOptions = () => {
    optionElements.forEach(item => {
        item.classList.remove('disabled', 'correct', 'wrong');
    })
}

const answerTracker = () => {
    questions.forEach(() => {
        const div = document.createElement('div');
        answersTracker.appendChild(div);
    })
};

const updateAnswerTracker = status => {
    answersTracker.children[indexOfPage - 1].classList.add(`${status}`);
}
const validate = () => {
    if (!optionElements[0].classList.contains('disabled')) {
        alert('Выберите один вариант ответа!');
    } else {
        randomQuestion();
        enableOptions();
    }
}

const quizOver = () => {
    document.querySelector('.quiz-over-modal').classList.add('active');
    correctAnswer.innerHTML = score;
    numberOfAllQuestion2.innerHTML = questions.length;
};

const tryAgain = () =>{
    window.location.reload();
}

btnTryAgain.addEventListener('click', tryAgain);
btnNext.addEventListener('click', () => {
    validate();
})

window.addEventListener('load', () => {
    randomQuestion();
    answerTracker();
})

