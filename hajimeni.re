#@# VRコンテンツのつくりかた3 技術書典4
#@# （）かっこは全角統一する。
#@# ユーザ入力は""ダブルクォーテーション、メニュー表示文字列は「」かぎかっこにでくくる。

= はじめに

はいどうもー。
バーチャルYouTuberが大好きなyoutenと申します。

バーチャルYouTuberがVRコンテンツか？というと直接的にはそうではないと思います。
しかし、使われている技術や、地続きとなっている技術・文化圏はVRであると言えるのではないでしょうか。
そんなわけで「VRコンテンツのつくりかた3 Hello, VTuber World!」と題しまして、「バーチャルYouTuberのやり方」を本書ではお届けします。
@<br>{}

本書は、以下のような方をターゲットにしています。

 * バーチャルYouTuberに使われている技術が知りたい
 * Unity+ViveベースのバーチャルYouTuberを試してみたい
 * Unityのプログラミングや3Dモデリングなどに興味、または経験があり、バーチャルYouTuberをやってみたい

== 本書の賞味期限とリポジトリ公開について

なお、本書は記載内容の賞味期限が切れてしまうことへのアップデート対応、あまり紙メディアが向いていない環境等のバージョンアップに追従するため、初版以降のPDFと関連ファイル一式を全て以下のリポジトリで公開予定です。
あらかじめご了承ください。

 * @<href>{https://github.com/youten/howto-create-vr-contents3}
 ** Re:VIEWの素材一式、出力PDF、関連プロジェクトのソースコードを全て含む想定です。

本書のうち、私youtenが著作権を有する範囲のライセンスについては、文章はCC-BY 4.0ライセンス@<fn>{cc-by-4}を適用します。

本書籍はRe:VIEWで作成されており、その設定ファイル等について、MITライセンスに基づき「C89 初めてのRe:VIEW v2」リポジトリ@<fn>{techbooster-c89-review-v2}で公開されているものを利用させていただいております。

//footnote[techbooster-c89-review-v2][@<href>{https://github.com/TechBooster/C89-FirstStepReVIEW-v2}]
//footnote[cc-by-4][@<href>{https://creativecommons.org/licenses/by/4.0/legalcode.ja}]
