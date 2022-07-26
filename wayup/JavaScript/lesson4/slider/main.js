const prev = document.getElementById('btn-prev'),
    next = document.getElementById('btn-next'),
    slides = document.querySelectorAll('.slide'),
    dots = document.querySelectorAll('.dot');

let index = 0;
let timer = 0;

const activeSlide = n => {
    for (slide of slides) {
        slide.classList.remove('active');
    }
    slides[n].classList.add('active');
}
const activeDot = n => {
    for (dot of dots) {
        dot.classList.remove('active');
    }
    dots[n].classList.add('active');
}

const prepareCurrSlide = ind => {
    activeSlide(index);
    activeDot(index);
}

const makeTimer = () => {
    clearInterval(timer);
    timer = setInterval(() => {
        if (index == slides.length - 1) {
            index = 0;
            prepareCurrSlide(index);
        } else {
            index++;
            prepareCurrSlide(index);
        }
    }, 5000);
}
const nextSlide = () => {
    if (index == slides.length - 1) {
        index = 0;
        prepareCurrSlide(index);
        makeTimer();
    } else {
        index++;
        prepareCurrSlide(index);
        makeTimer();
    }
}
const prevSlide = () => {
    if (index == 0) {
        index = slides.length - 1;
        prepareCurrSlide(index);
        makeTimer();
    } else {
        index--;
        prepareCurrSlide(index);
        makeTimer();
    }
}

dots.forEach((item, indexDot) => {
    item.addEventListener('click', () => {
        index = indexDot;
        prepareCurrSlide(index);
        makeTimer();
    })
})

makeTimer();


next.addEventListener('click', nextSlide);
prev.addEventListener('click', prevSlide);
