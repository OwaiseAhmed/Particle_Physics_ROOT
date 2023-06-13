void ntaus()
{

    TH1F *hist_ntau = new TH1F("nTau ", "histogram", 50, -05, 49.5);

    TFile *file = new TFile("DYJetsToLL.root");

    TTree *Tree= (TTree *)file->Get("Events");

hist_ntau->GetXaxis()->SetTitle("nTau");

    uint ntau;
    int nentires = Tree->GetEntries();

    Tree->SetBranchAddress("nTau", &ntau);

    for (int i = 0; i < nentires; i++)
    {

        Tree->GetEntry(i);
        hist_ntau->Fill(ntau);
    }

    TCanvas *c2 = new TCanvas();
    hist_ntau->Draw();

    return;
}
