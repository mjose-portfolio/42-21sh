/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_exec_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiche <bsiche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 18:22:41 by mjose             #+#    #+#             */
/*   Updated: 2019/04/15 00:09:00 by bsiche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void		set_new_process(t_jobs *job, pid_t pid0)
{
	new_process(job, pid0);
	if (job->jpid == 0)
		job->jpid = pid0;
	setpgid(pid0, job->jpid);
}

void		set_jobs(t_jobs *job, pid_t pid0)
{
	pid0 = getpid();
	if (job->jpid == 0)
		job->jpid = pid0;
	setpgid(pid0, job->jpid);
	if (job->background == 0)
		tcsetpgrp(g_tracking.sterminal, job->jpid);
	set_process_signal_handlers();
}
