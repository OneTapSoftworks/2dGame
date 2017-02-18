#pragma once
#include "Vars.h"

static PyObject *SpamError;

////////////////////////////////////

/*

	DEBUG MODULE

*/

static PyObject *
debug_log(PyObject *self, PyObject *args)
{
	const char *command;
	int sts;

	if (!PyArg_ParseTuple(args, "s", &command))
		return NULL;
	//sts = system(command);
	printf("[LOG] ");
	printf(command);
	printf("\n");
	if (sts < 0) {
		PyErr_SetString(SpamError, "System command failed");
		return NULL;
	}
	return PyLong_FromLong(sts);
}

static PyObject *
debug_warning(PyObject *self, PyObject *args)
{
	const char *command;
	int sts;

	if (!PyArg_ParseTuple(args, "s", &command))
		return NULL;
	//sts = system(command);
	printf("[WARNING] ");
	printf(command);
	printf("\n");
	if (sts < 0) {
		PyErr_SetString(SpamError, "System command failed");
		return NULL;
	}
	return PyLong_FromLong(sts);
}

static PyObject *
debug_error(PyObject *self, PyObject *args)
{
	const char *command;
	int sts;

	if (!PyArg_ParseTuple(args, "s", &command))
		return NULL;
	//sts = system(command);
	printf("[ERROR] ");
	printf(command);
	printf("\n");
	if (sts < 0) {
		PyErr_SetString(SpamError, "System command failed");
		return NULL;
	}
	Sleep(3000);
	exit(0);
	return PyLong_FromLong(sts);
}

/*

	PLAYER MODULE

*/

static PyObject *
player_move(PyObject *self, PyObject*args)
{
	int sts;
	player->MoveX(200);
	cout << "przeniesiono gracza!" << endl;
	return Py_BuildValue("i", sts);
}

/////////////////////////////////////
static PyMethodDef DebugMethods[] = {
	{ "log", debug_log, METH_VARARGS, "Send a log msg into CMD." },
	{ "warning", debug_warning, METH_VARARGS, "Send a log warning into CMD." },
	{ "error", debug_error, METH_VARARGS, "Send a log error into CMD and close program." },
	{ NULL, NULL, 0, NULL }
};
static PyMethodDef PlayerMethods[] = {
	{ "move",  player_move, METH_VARARGS, "Moves a player." },
	{ NULL, NULL, 0, NULL }
};