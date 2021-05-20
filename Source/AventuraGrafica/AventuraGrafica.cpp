// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "AventuraGrafica.h"
#include "Modules/ModuleManager.h"
#include "Globals.h"

IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, AventuraGrafica, "AventuraGrafica" );

DEFINE_LOG_CATEGORY(GraphicAdventure)

FName Globals::ItemBase_CollisionOverrideable = "CollisionOverrideable";