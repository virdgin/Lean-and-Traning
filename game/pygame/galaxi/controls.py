import pygame
import sys
from bullet import Bullet
from in1 import Inop1
import time


def events(screen, gun, bullets):
    """Прослушка событий"""
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            sys.exit()
        elif event.type == pygame.KEYDOWN:
            # вправо
            if event.key == pygame.K_RIGHT:
                gun.mright = True
            # влево
            elif event.key == pygame.K_LEFT:
                gun.mleft = True
            elif event.key == pygame.K_SPACE:
                """СТРЕЛЬБА"""
                new_bullet = Bullet(screen, gun)
                bullets.add(new_bullet)
        elif event.type == pygame.KEYUP:
            # вправо
            if event.key == pygame.K_RIGHT:
                gun.mright = False
            # влево
            elif event.key == pygame.K_LEFT:
                gun.mleft = False


def update(bg_color, screen, gun, inos, bullets):
    """обновление экрана"""
    screen.blit(bg_color, (0, 0))
    for bullet in bullets.sprites():  # прорисовываем пули до пушки
        bullet.draw_bullet()
    gun.output()
    inos.draw(screen)
    pygame.display.flip()


def update_bullet(screen, inos, bullets):
    """обновление местоположения пуль"""
    bullets.update()
    for bullet in bullets.copy():
        if bullet.rect.bottom <= 0:
            bullets.remove(bullet)
    collisions = pygame.sprite.groupcollide(
        bullets, inos, True, True
    )  # пересечение пули и пришельцевб 1 True исчезает пуля 2 True исчезает пришелец
    if len(inos) == 0:
        bullets.empty()
        create_army(screen, inos)

def update_inos(stats, screen, gun, inos, bullets):
    """обновляет позицию пришельцев"""
    inos.update()
    if pygame.sprite.spritecollideany(
        gun, inos
    ):  # пересечение пришельцев и пушки если пересеклись то выполняется действие
        gun_kill(stats, screen, gun, inos, bullets)
    inos_check(stats, screen, gun, inos, bullets)


def inos_check(stats, screen, gun, inos, bullets):
    """добралась лит армия до края"""
    screen_rect = screen.get_rect()  # получаем прямоугольник экрана
    for ino in inos.sprites():
        if ino.rect.bottom >= screen_rect.bottom:
            gun_kill(stats, screen, gun, inos, bullets)
            break


def gun_kill(stats, screen, gun, inos, bullets):
    """столкновение пушки и пришельцев"""
    stats.guns_left -= 1
    inos.empty()
    bullets.empty()
    create_army(screen, inos)
    gun.create_gun()
    time.sleep(2)


def create_army(screen, inos):
    """создаём группу пришельцев"""
    ino = Inop1(screen)
    ino_width = ino.rect.width + 20  # длина одного пришельца
    # рассчёт сколько надо пришельцев в ряду
    number_ino_x = int((800 - 2 * ino_width) / ino_width)
    ino_height = ino.rect.height + 10
    number_ino_y = int(
        ((600 - 70) - 2 * ino_height) / ino_height
    )  # рассчёт сколько рядов
    for row_number in range(number_ino_y - 5):
        for number_ino in range(number_ino_x):
            ino = Inop1(screen)
            ino.x = ino_width + ino_width * number_ino
            ino.y = ino_height + ino_height * row_number
            ino.rect.x = ino.x
            ino.rect.y = ino.rect.height + 2 * ino.rect.height * row_number 
            inos.add(ino)
