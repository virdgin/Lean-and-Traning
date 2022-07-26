const gulp = require('gulp'),
    browserSync = require('browser-sync').create();
const pug = require('gulp-pug'),
    sass = require('gulp-sass')(require('sass'));

const app = 'app/',
    dist = 'dist/';

const config = {
    app: {
        html: app + 'pug/index.pug',
        style: app + 'scss/**/*.*',
        js: app + 'js/**/*.*',
        font: app + 'fonts/**/*.*',
        img: app + 'img/**/*.*'
    },
    dist: {
        html: dist,
        style: dist + 'css/',
        js: dist + 'js/',
        font: dist + 'fonts/',
        img: dist + 'img/'
    },
    watch: {
        html: app + 'pug/index.pug',
        style: app + 'scss/**/*.*',
        js: app + 'js/**/*.*',
        font: app + 'fonts/**/*.*',
        img: app + 'img/**/*.*'
    }
}

const webServer = () => {
    browserSync.init({
        server: {
            baseDir: dist
        },
        port: 8000,
        host: 'localhost',
        notify: false
    })
}

const pugTask = () => {
    return gulp.src(config.app.html)
        .pipe(pug())
        .pipe(pug({
            pretty: false
        }))
        .pipe(gulp.dest(config.dist.html))
        .pipe(browserSync.reload({ stream: true }))
}

const scssTask = () => {
    return gulp.src(config.app.style)
        .pipe(sass().on('error', sass.logError))
        .pipe(gulp.dest(config.dist.style))
        .pipe(browserSync.reload({ stream: true }))
}
const watchFiles = () => {
    gulp.watch([config.watch.html], gulp.series(pugTask));
    gulp.watch([config.watch.style], gulp.series(scssTask));
}

const start = gulp.series(pugTask, scssTask);

exports.default = gulp.parallel(start, watchFiles, webServer);