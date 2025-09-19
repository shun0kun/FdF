/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimots <sshimots@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 09:40:52 by sshimots          #+#    #+#             */
/*   Updated: 2025/09/19 19:10:25 by sshimots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line_and_trim(char *stash)
{
	char	*line;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (stash[i] != '\n')
		i++;
	line = malloc(i + 2);
	i = 0;
	while (stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i++] = '\n';
	line[i] = '\0';
	while (stash[i + j])
	{
		stash[j] = stash[i + j];
		j++;
	}
	stash[j] = '\0';
	return (line);
}

void	free_and_nullify(char **p)
{
	free(*p);
	*p = NULL;
}

char	*extend(char *stash, char *s)
{
	size_t	i;
	size_t	j;
	char	*new_stash;

	i = 0;
	j = 0;
	if (!stash)
	{
		new_stash = malloc(gnl_strlen(s) + 1);
		while (s[i])
		{
			new_stash[i] = s[i];
			i++;
		}
		new_stash[i] = '\0';
		free(s);
		return (new_stash);
		// return (s);
	}
	new_stash = malloc((gnl_strlen(stash) + gnl_strlen(s) + 1) * sizeof(char));
	if (!new_stash)
		return (free_and_return_null(&stash, &s));
	while (stash[i])
	{
		new_stash[i] = stash[i];
		i++;
	}
	while (s[j])
	{
		new_stash[i + j] = s[j];
		j++;
	}
	new_stash[i + j] = '\0';
	// free_and_nullify(&stash);
	// free_and_nullify(&s);
	free(stash);
	free(s);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*s;
	ssize_t		buf;

	if (stash && has_line_break(stash))
		return (get_line_and_trim(stash));
	while (1)
	{
		s = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!s)
			return (free_and_return_null(&stash, &s));
		buf = read(fd, s, BUFFER_SIZE);
		if (((buf == 0 && (!stash || gnl_strlen(stash) == 0)))|| buf == -1)
			return (free_and_return_null(&stash, &s));
		s[buf] = '\0';
		stash = extend(stash, s);
		// s = NULL;
		if (!stash)
			return (NULL);
		if (has_line_break(stash))
			return (get_line_and_trim(stash));/*stashは空文字*/
		else if (buf != BUFFER_SIZE)
		{
			s = stash;
			stash = NULL;
			return (s);
		}
	}
}

//get_new_lineを呼び出した時に、stashの中身に改行がなく、かつファイルをすでに読み切っているときに、残りのstashを返さずにNULLだけ返してしまってる。
//"aaa\naaa"なるファイルの時、上に加えてダブルフリーもしてるらしい。free_and_return_null関数でダブルフリーしてるみたい。片方のフリーをコメントアウトしたらうまく出力されたから。
//ファイルを読み切ったあとに空文字を返してしまっている！（重要）"\n"←例
//stashが空文字かつすでに読み切ってる場合がだめ。
//read = -1のときにダブルフリーしてるかも
//stash
//BUFFER_SIZEが改行なしのファイルの文字数と一致してる時に、if(buf != BUFFER_SIZE)あたりから危うい。無限ループするくない？→大丈夫だった。
//if (buf != BUFFER_SIZE) で最後の文字列を返すんじゃなくて、read == 0の時にstashの中にまだ文字が一つ以上あったらそれを返してstashをnullにするのでも良さそう。
