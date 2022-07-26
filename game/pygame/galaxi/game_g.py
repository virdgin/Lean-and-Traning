import pygame
import controls
from gun import Gun
from pygame.sprite import Group
from stats import Stats


def run():

    pygame.init()
    screen = pygame.display.set_mode((1024, 600))
    pygame.display.set_caption('Космостар')
    bg_color = pygame.image.load('galaxi\images\cosmos.jpg')
    gun = Gun(screen)
    bullets = Group()
    inos = Group()
    controls.create_army(screen, inos)
    stats = Stats()
    while True:
        controls.events(screen, gun, bullets)
        gun.update_gun()
        controls.update(bg_color, screen, gun, inos, bullets)
        controls.update_bullet(screen, inos, bullets)
        controls.update_inos(stats, screen, gun, inos, bullets)

run()
