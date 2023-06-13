
void nmuon()
{

    TH1F *hist_muon = new TH1F("Number of Muons", "nMuon", 50, -0.5, 49.5);

    TFile *file = new TFile("DYJetsToLL.root");

    TTree *Tree = (TTree *)file->Get("Events");

hist_muon->GetXaxis()->SetTitle("nMuon");

    uint nMuon;

    int nentires = Tree->GetEntries();

    Tree->SetBranchAddress("nMuon", &nMuon);

    for (int i = 0; i < nentires; i++)
    {

        Tree->GetEntry(i);
        hist_muon->Fill(nMuon);
    }

    TCanvas *c4 = new TCanvas();
    hist_muon->Draw();



    return;
}
