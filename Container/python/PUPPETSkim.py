from MitAna.TreeMod.bambu import mithep

puppetSkimTree = mithep.TreeContainer()
puppetSkimTree.SetTreeName("PUPPET/t")
puppetSkimTree.SetPrinting(True)
puppetSkimTree.SetSkimmingTrees(True)
puppetSkimTree.AddKeepBranch("recoilPFPuppiMet_Pt")
puppetSkimTree.AddKeepBranch("recoilPFPuppiMet_PerpZ")
puppetSkimTree.AddKeepBranch("recoilPFPuppiMet_LongZ")
#puppetSkimTree.AddKeepBranch("recoilPFMet_Pt")
#puppetSkimTree.AddKeepBranch("recoilPFMet_PerpZ")
#puppetSkimTree.AddKeepBranch("recoilPFMet_LongZ")
puppetSkimTree.AddKeepBranch("Boson_Pt")
puppetSkimTree.AddKeepBranch("Boson_daughter")
puppetSkimTree.AddKeepBranch("NVertex")
