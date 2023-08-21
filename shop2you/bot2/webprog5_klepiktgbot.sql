-- phpMyAdmin SQL Dump
-- version 5.2.0
-- https://www.phpmyadmin.net/
--
-- Хост: localhost:3306
-- Время создания: Июл 23 2023 г., 14:17
-- Версия сервера: 10.6.7-MariaDB-1:10.6.7+maria~bullseye
-- Версия PHP: 8.1.3

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- База данных: `webprog5_klepiktgbot`
--

-- --------------------------------------------------------

--
-- Структура таблицы `klepiktgbot_admin_id`
--

CREATE TABLE `klepiktgbot_admin_id` (
  `id` int(10) UNSIGNED NOT NULL,
  `admin_name` varchar(20) NOT NULL COMMENT 'ник админа',
  `first_name` varchar(20) NOT NULL COMMENT 'имя админа',
  `last_name` varchar(20) NOT NULL COMMENT 'фамилия',
  `titlegroup_id` int(10) UNSIGNED NOT NULL COMMENT 'в какой группе состоит'
) ENGINE=InnoDB DEFAULT CHARSET=cp1251 COMMENT='список админов';

--
-- Дамп данных таблицы `klepiktgbot_admin_id`
--

INSERT INTO `klepiktgbot_admin_id` (`id`, `admin_name`, `first_name`, `last_name`, `titlegroup_id`) VALUES
(1, 'aklepik', 'Aleksandr', 'Klepik', 1);

-- --------------------------------------------------------

--
-- Структура таблицы `klepiktgbot_homework_id`
--

CREATE TABLE `klepiktgbot_homework_id` (
  `id` int(10) UNSIGNED NOT NULL,
  `max_devilery_data` date NOT NULL COMMENT 'максимальная дата сдачи',
  `description` text NOT NULL COMMENT 'описание',
  `max_rating` int(10) UNSIGNED NOT NULL COMMENT 'максимальная оценка',
  `titlegroup_id` int(10) UNSIGNED NOT NULL COMMENT 'из какой группы дз'
) ENGINE=InnoDB DEFAULT CHARSET=cp1251 COMMENT='домашние задания';

--
-- Дамп данных таблицы `klepiktgbot_homework_id`
--

INSERT INTO `klepiktgbot_homework_id` (`id`, `max_devilery_data`, `description`, `max_rating`, `titlegroup_id`) VALUES
(1, '2023-07-19', 'Создать БД', 100, 1),
(2, '2023-07-24', 'all incl', 100, 1);

-- --------------------------------------------------------

--
-- Структура таблицы `klepiktgbot_rating_id`
--

CREATE TABLE `klepiktgbot_rating_id` (
  `id` int(10) UNSIGNED NOT NULL,
  `homework_id` int(11) UNSIGNED NOT NULL COMMENT 'какая домашняя работа',
  `rating` int(3) UNSIGNED NOT NULL COMMENT 'оценка',
  `admin_id` int(11) UNSIGNED NOT NULL COMMENT 'поставил',
  `devilery_data` date NOT NULL COMMENT 'дата сдачи работы',
  `completion mark` tinyint(1) UNSIGNED NOT NULL COMMENT 'отметка о выполнении'
) ENGINE=InnoDB DEFAULT CHARSET=cp1251 COMMENT='оценки';

--
-- Дамп данных таблицы `klepiktgbot_rating_id`
--

INSERT INTO `klepiktgbot_rating_id` (`id`, `homework_id`, `rating`, `admin_id`, `devilery_data`, `completion mark`) VALUES
(1, 1, 100, 1, '2023-07-18', 1);

-- --------------------------------------------------------

--
-- Структура таблицы `klepiktgbot_titlegroup_id`
--

CREATE TABLE `klepiktgbot_titlegroup_id` (
  `id` int(10) UNSIGNED NOT NULL,
  `titlegroup` varchar(20) NOT NULL COMMENT 'название',
  `description` text NOT NULL COMMENT 'описание',
  `id_tggroup` int(10) NOT NULL COMMENT 'ID телеграмгруппы'
) ENGINE=InnoDB DEFAULT CHARSET=cp1251 COMMENT='группы телеграмм';

--
-- Дамп данных таблицы `klepiktgbot_titlegroup_id`
--

INSERT INTO `klepiktgbot_titlegroup_id` (`id`, `titlegroup`, `description`, `id_tggroup`) VALUES
(1, 'test_group_bot', '', -905661021),
(2, '1561', '51612', 515614321);

-- --------------------------------------------------------

--
-- Структура таблицы `klepiktgbot_user_id`
--

CREATE TABLE `klepiktgbot_user_id` (
  `id` int(10) UNSIGNED NOT NULL,
  `username` varchar(50) NOT NULL COMMENT 'ник юзера',
  `first_name` varchar(20) NOT NULL COMMENT 'имя юзера',
  `last_name` varchar(20) NOT NULL COMMENT 'фамилия юзера',
  `titlegroup_id` int(10) UNSIGNED NOT NULL COMMENT 'в какой группе состоит',
  `rating_id` int(10) UNSIGNED NOT NULL COMMENT 'оценки',
  `homework_id` int(10) UNSIGNED NOT NULL COMMENT 'домашние работы'
) ENGINE=InnoDB DEFAULT CHARSET=cp1251 COMMENT='список пользователей';

--
-- Дамп данных таблицы `klepiktgbot_user_id`
--

INSERT INTO `klepiktgbot_user_id` (`id`, `username`, `first_name`, `last_name`, `titlegroup_id`, `rating_id`, `homework_id`) VALUES
(1, 'bzik', 'Сергей', '', 1, 1, 1);

--
-- Индексы сохранённых таблиц
--

--
-- Индексы таблицы `klepiktgbot_admin_id`
--
ALTER TABLE `klepiktgbot_admin_id`
  ADD PRIMARY KEY (`id`),
  ADD KEY `titlegroup_id` (`titlegroup_id`);

--
-- Индексы таблицы `klepiktgbot_homework_id`
--
ALTER TABLE `klepiktgbot_homework_id`
  ADD PRIMARY KEY (`id`),
  ADD KEY `titlegroup_id` (`titlegroup_id`);

--
-- Индексы таблицы `klepiktgbot_rating_id`
--
ALTER TABLE `klepiktgbot_rating_id`
  ADD PRIMARY KEY (`id`),
  ADD KEY `admin_id` (`admin_id`),
  ADD KEY `homework_id` (`homework_id`);

--
-- Индексы таблицы `klepiktgbot_titlegroup_id`
--
ALTER TABLE `klepiktgbot_titlegroup_id`
  ADD PRIMARY KEY (`id`);

--
-- Индексы таблицы `klepiktgbot_user_id`
--
ALTER TABLE `klepiktgbot_user_id`
  ADD PRIMARY KEY (`id`),
  ADD KEY `titlegroup_id` (`titlegroup_id`),
  ADD KEY `rating_id` (`rating_id`),
  ADD KEY `homework_id` (`homework_id`);

--
-- AUTO_INCREMENT для сохранённых таблиц
--

--
-- AUTO_INCREMENT для таблицы `klepiktgbot_admin_id`
--
ALTER TABLE `klepiktgbot_admin_id`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT для таблицы `klepiktgbot_homework_id`
--
ALTER TABLE `klepiktgbot_homework_id`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- AUTO_INCREMENT для таблицы `klepiktgbot_rating_id`
--
ALTER TABLE `klepiktgbot_rating_id`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT для таблицы `klepiktgbot_titlegroup_id`
--
ALTER TABLE `klepiktgbot_titlegroup_id`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- AUTO_INCREMENT для таблицы `klepiktgbot_user_id`
--
ALTER TABLE `klepiktgbot_user_id`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- Ограничения внешнего ключа сохраненных таблиц
--

--
-- Ограничения внешнего ключа таблицы `klepiktgbot_admin_id`
--
ALTER TABLE `klepiktgbot_admin_id`
  ADD CONSTRAINT `klepiktgbot_admin_id_ibfk_1` FOREIGN KEY (`titlegroup_id`) REFERENCES `klepiktgbot_titlegroup_id` (`id`);

--
-- Ограничения внешнего ключа таблицы `klepiktgbot_homework_id`
--
ALTER TABLE `klepiktgbot_homework_id`
  ADD CONSTRAINT `klepiktgbot_homework_id_ibfk_2` FOREIGN KEY (`titlegroup_id`) REFERENCES `klepiktgbot_titlegroup_id` (`id`);

--
-- Ограничения внешнего ключа таблицы `klepiktgbot_rating_id`
--
ALTER TABLE `klepiktgbot_rating_id`
  ADD CONSTRAINT `klepiktgbot_rating_id_ibfk_1` FOREIGN KEY (`admin_id`) REFERENCES `klepiktgbot_admin_id` (`id`),
  ADD CONSTRAINT `klepiktgbot_rating_id_ibfk_2` FOREIGN KEY (`homework_id`) REFERENCES `klepiktgbot_homework_id` (`id`);

--
-- Ограничения внешнего ключа таблицы `klepiktgbot_user_id`
--
ALTER TABLE `klepiktgbot_user_id`
  ADD CONSTRAINT `klepiktgbot_user_id_ibfk_1` FOREIGN KEY (`titlegroup_id`) REFERENCES `klepiktgbot_titlegroup_id` (`id`),
  ADD CONSTRAINT `klepiktgbot_user_id_ibfk_2` FOREIGN KEY (`rating_id`) REFERENCES `klepiktgbot_rating_id` (`id`),
  ADD CONSTRAINT `klepiktgbot_user_id_ibfk_3` FOREIGN KEY (`homework_id`) REFERENCES `klepiktgbot_homework_id` (`id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
