// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class ProjCoreIEditor_NoPrecompTarget : ProjCoreIEditorTarget
{
	public ProjCoreIEditor_NoPrecompTarget(TargetInfo Target) : base(Target)
	{
		bUseUnityBuild = false;
		bUsePCHFiles = false;
	}
}
