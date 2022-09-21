#include <iostream>
#include <tuple>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

TaskStatus Next(TaskStatus task_status)
{
    return static_cast<TaskStatus>(static_cast<int>(task_status) + 1);
}
// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

class TeamTasks
{
public:
    // Получить статистику по статусам задач конкретного разработчика
    const TasksInfo &GetPersonTasksInfo(const string &person) const
    {
        return task_person.at(person);
    }

    // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
    void AddNewTask(const string &person)
    {
        ++task_person[person][TaskStatus::NEW];
    }

    // Обновить статусы по данному количеству задач конкретного разработчика,
    // подробности см. ниже
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(
        const string &person, int task_count)
    {
        TasksInfo updated_tasks, untouched_tasks;
        TasksInfo &task = task_person[person];
        for (TaskStatus status = TaskStatus::NEW;
             status != TaskStatus::DONE;
             status = Next(status))
        {
            updated_tasks[Next(status)] = min(task_count, task[status]);
            task_count -= updated_tasks[Next(status)];
        }
        for (TaskStatus status = TaskStatus::NEW;
             status != TaskStatus::DONE;
             status = Next(status))
        {
            untouched_tasks[status] = task[status] - updated_tasks[Next(status)];
            task[status] += updated_tasks[status] - updated_tasks[Next(status)];
        }
        task[TaskStatus::DONE] += updated_tasks[TaskStatus::DONE];
        Zeros(updated_tasks);
        Zeros(untouched_tasks);
        Zeros(task_person.at(person));
        return {updated_tasks, untouched_tasks};
    }
    void Zeros(TasksInfo &task_info)
    {
        vector<TaskStatus> status_remove;
        for (const auto &info : task_info)
        {
            if (info.second == 0)
            {
                status_remove.push_back(info.first);
            }
        }
        for (const auto &stat : status_remove)
        {
            task_info.erase(stat);
        }
    }

private:
    map<string, TasksInfo> task_person;
};
