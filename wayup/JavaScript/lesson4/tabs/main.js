const tabs = document.getElementById('tabs');
const content = document.querySelectorAll('.content');
const tabIn = document.getElementById('tabs-in')

const changeClass = elm => {
    for (let i = 0; i < tabs.children.length; i++) {
        tabs.children[i].classList.remove('active');
    }
    elm.classList.add('active');
}

const changeTabs = el => {
    const currT = el.dataset.btn;
    for (let i = 0; i < tabIn.children.length; i++) {
        tabIn.children[i].classList.remove('active');
    }
    if (currT == 3) {
        tabIn.children[0].classList.add('active');
    } else {
        el.classList.add('active');
    }
}
const changeContent = ele => {
    const currTab = ele.target.dataset.btn;
    if (currTab >= 3) {
        tabIn.classList.remove('show');
        changeTabs(ele.target);
    } else {
        tabIn.classList.add('show');

    }
    for (let i = 0; i < content.length; i++) {
        content[i].classList.remove('active');
        if (content[i].dataset.content === currTab) {
            content[i].classList.add('active');
        }

    }
}
tabs.addEventListener('click', e => {
    changeClass(e.target);
    changeContent(e);

})

tabIn.addEventListener('click', je => {
    changeTabs(je.target);
    changeContent(je);

})

